# Atlas C1

Robot di động 4 bánh mecanum (holonomic), chạy **ROS 2 Humble**, điều khiển động cơ qua vi điều khiển **ESP32** nối bằng serial, dùng **YDLidar X3 Pro** làm cảm biến chính cho SLAM/định vị/tránh vật cản, và **Nav2** cho điều hướng tự động.

Kiến trúc chia làm 2 máy tính:
- **Robot (onboard, NUC)**: chạy phần cứng — LiDAR, cầu nối serial tới ESP32, động học mecanum.
- **PC (máy tính điều khiển)**: chạy mô tả robot (URDF/RViz), lọc/relay scan, odometry, joystick, SLAM/Nav2.

Hai máy giao tiếp qua chung một ROS domain (Wi-Fi/LAN) — không có message-bridge riêng, tất cả là topic/service ROS 2 thông thường.

> Tài liệu này mô tả **đúng trạng thái code hiện tại**, bao gồm cả những phần chưa hoàn chỉnh/không nhất quán (xem mục [Vấn đề đã biết](#vấn-đề-đã-biết--hạn-chế)) — không phải trạng thái lý tưởng.

---

## Mục lục
- [Sơ đồ hệ thống](#sơ-đồ-hệ-thống)
- [Cấu trúc thư mục](#cấu-trúc-thư-mục)
- [Phần cứng](#phần-cứng)
- [Chi tiết từng package](#chi-tiết-từng-package)
- [Thuật toán sử dụng](#thuật-toán-sử-dụng)
- [Cài đặt & build](#cài-đặt--build)
- [Vận hành](#vận-hành)
- [Vấn đề đã biết / hạn chế](#vấn-đề-đã-biết--hạn-chế)

---

## Sơ đồ hệ thống

```
┌───────────────────────────── ROBOT (NUC) ─────────────────────────────┐
│                                                                        │
│  YDLidar X3 Pro ──/dev/ydlidar──▶ ydlidar_ros2_driver_node ──/scan──┐  │
│                                                                     │  │
│  ESP32 (PID bánh xe) ──/dev/esp32 (serial, frame 0x2a..0x23)──▶     │  │
│         ▲                                    ros_serial_bridge.py  │  │
│         │ Velquery (RPM 4 bánh)                     ▲              │  │
│         │                                            │ /vel_query  │  │
│         └──────────── kinematic.py ◀──── /cmd_vel ───┘              │  │
│                                                                     │  │
└─────────────────────────────────────────────────────────────────────┘  │
                                                                          │
┌───────────────────────────── PC ──────────────────────────────────────┼──┐
│                                                                        │  │
│  robot_state_publisher + mecanum_joint_publisher (RViz)  /scan ◀───────┘  │
│                                                                           │
│  scan_relay (topic_tools) : /scan ──▶ /atlas/scan_filtered               │
│                                              │                           │
│                                              ▼                           │
│                                    rf2o_laser_odometry ──▶ /atlas/odom   │
│                                                                           │
│  joy_node ──/joy──▶ teleop_twist_joy ────────────▶ /cmd_vel_joy ─┐        │
│                └──▶ lateral_teleop_node.py ──────▶ /cmd_vel_lateral │     │
│                                                                    ▼     │
│                                                    twist_mux ──▶ /cmd_vel│
│                                                    (nav=50 < joy=100     │
│                                                     < lateral=150)       │
│                                                                           │
│  atlas_slam: slam_toolbox (mapping) / AMCL (localization) / Nav2 (MPPI) │
│                                                                           │
└───────────────────────────────────────────────────────────────────────┘
```

---

## Cấu trúc thư mục

| Package | Loại | Vai trò |
|---|---|---|
| `c1_bringup` | ament_cmake | Launch file tổng hợp cho robot/PC, config port thiết bị, joystick + twist_mux |
| `c1_driver` | ament_cmake (+ rosidl) | Node động học mecanum (`kinematic.py`), cầu nối serial tới ESP32 (`ros_serial_bridge.py`), msg tuỳ biến `Velquery`/`Velinfo` |
| `c1_description` | ament_cmake | URDF robot (mecanum 4 bánh), node giả lập khớp bánh xe cho RViz |
| `c1_sdk/ydlidar_ros2_driver` | vendored, ament_cmake | Driver ROS 2 chính hãng cho họ LiDAR YDLidar |
| `c1_sdk/rf2o_laser_odometry` | vendored, ament_cmake | Odometry từ laser scan (range-flow scan matching) |
| `atlas_slam` | ament_cmake | Launch + config cho mapping (slam_toolbox), localization (AMCL), Nav2 (MPPI), collision monitor |
| `c1_maps` | dữ liệu (không phải package) | Bản đồ đã lưu (`map1/`, `map2/`) — pose-graph của slam_toolbox |
| `ESP32_code` | PlatformIO (không phải ROS) | Firmware ESP32: PID tốc độ bánh, giao tiếp serial |
| `c1_platform` | ament_cmake | **Stub rỗng**, chưa có nội dung |
| `docs/` | — | `dev_port.md` (udev rule cho `/dev/esp32`, `/dev/ydlidar`), `run_robot.md` (quy trình vận hành) |

Repo còn khai báo submodule `src/atlas_base` (trong `.gitmodules`) nhưng **chưa được checkout** — không dùng được ở trạng thái hiện tại.

---

## Phần cứng

- **Khung robot**: mecanum 4 bánh (bánh trước trái/phải, sau trái/phải), cho phép di chuyển toàn hướng (holonomic) — tiến/lùi, quay, và đi ngang (strafe).
- **LiDAR**: YDLidar X3 Pro, 2D, single-channel, range 0.1–12 m, 10 Hz, kết nối serial 115200 baud qua `/dev/ydlidar` (symlink udev cố định theo cổng USB vật lý).
- **Bộ điều khiển động cơ**: ESP32, nhận lệnh RPM từng bánh qua serial (115200 baud, `/dev/esp32`), chạy vòng lặp **PID tốc độ bánh xe cục bộ** dựa trên encoder đọc bằng PCNT (pulse counter) của ESP32, xuất PWM ra driver động cơ (H-bridge, 2 kênh PWM/động cơ).
- **Máy tính onboard**: NUC (chạy `c1_bringup_robot.launch.py`).
- **Tay cầm điều khiển**: joystick chuẩn (qua `joy_node`), có 2 nút bấm số dùng riêng để đi ngang (mecanum strafe) ngoài cần analog tiến/lùi/quay.

---

## Chi tiết từng package

### `c1_bringup`
Gói tập hợp launch + config, không chứa thuật toán riêng.

- `c1_bringup_robot.launch.py` — chạy **trên robot**: `ydlidar_ros2_driver_node`, `ros_serial_bridge.py`, `kinematic.py`.
- `c1_bringup_pc.launch.py` — chạy **trên PC**: `robot_state_publisher`/`mecanum_joint_publisher` (qua `c1_description`), `scan_relay` (`/scan` → `/atlas/scan_filtered`), `rf2o_laser_odometry`, `joystick.launch.py`.
- `driver.launch.py` — launch phụ/dự phòng chỉ gồm `ros_serial_bridge` + `kinematic`, phần lớn trùng với `c1_bringup_robot.launch.py`.
- `joystick.launch.py` — `joy_node` → `/joy`; `teleop_twist_joy` → `/cmd_vel_joy`; `lateral_teleop_node.py` (node tự viết, đọc `buttons[]` thô cho 2 nút đi ngang) → `/cmd_vel_lateral`; `twist_mux` gộp `cmd_vel_nav` (priority 50) / `cmd_vel_joy` (100) / `cmd_vel_lateral` (150) → `/cmd_vel`.
- `config/devices.yaml` — nơi **duy nhất** cần sửa khi đổi cổng serial (`/dev/esp32`, `/dev/ydlidar`) hay baudrate.
- `config/joystick.yaml` — mapping trục/nút joystick, scale tốc độ, tham số debounce nút đi ngang (`hold_time`).

### `c1_driver`
- `kinematic.py`: subscribe `/cmd_vel` (`geometry_msgs/Twist`), tính động học nghịch mecanum ra RPM 4 bánh, publish `Velquery` trên `/vel_query`. Có watchdog: không nhận `/cmd_vel` > 1s thì tự đưa RPM về 0.
- `ros_serial_bridge.py`: subscribe `Velquery`, đóng gói thành frame nhị phân `0x2a + id(4B) + 8 byte dữ liệu + 0x23`, ghi ra serial cho ESP32; có luồng nền đọc phản hồi từ ESP32 nhưng **chưa publish lại vào ROS**.
- `msg/Velquery.msg`: lệnh RPM theo cặp (hướng, tốc độ) cho 4 bánh (FL/FR/RL/RR).
- `msg/Velinfo.msg`: định nghĩa sẵn cho telemetry phản hồi từ ESP32, nhưng **hiện chưa được publish ở đâu cả** (dead code).

### `c1_description`
- `urdf/c1_robot.urdf` (file `.urdf` thuần, không dùng xacro): `base_link` + 4 khớp `continuous` cho bánh mecanum, mỗi bánh mô hình hoá 8 con lăn nghiêng quanh hub (đúng kiểu bánh mecanum thật), khung nâng gắn `nuc` và `laser_frame`.
- `mecanum_joint_publisher.py`: subscribe `/cmd_vel`, tính vận tốc góc từng bánh bằng ma trận động học mecanum, tích phân ra góc khớp giả lập, publish `JointState` ở 50 Hz — **chỉ phục vụ hiển thị RViz**, không phản ánh encoder thật.
- `display.launch.py`: chạy `robot_state_publisher` + `mecanum_joint_publisher` (RViz2 và `joint_state_publisher_gui` đang bị comment).

### `c1_sdk` (vendor bên thứ ba)
- `ydlidar_ros2_driver`: driver chính hãng YDLidar, có sẵn param mẫu cho nhiều dòng lidar (X2/X3/X4/G-series/TG/...); project này không dùng param mẫu mà override toàn bộ qua `devices.yaml`.
- `rf2o_laser_odometry`: odometry bằng **range-flow scan matching** (không phải ICP theo điểm-điểm) — ước lượng vận tốc robot bằng cách khớp gradient của scan liên tiếp, publish `nav_msgs/Odometry` + TF `odom → base_link`.

### `atlas_slam`
Launch + config cho toàn bộ pipeline lập bản đồ / định vị / điều hướng:

- **Mapping**: `atlas_slam_toolbox_real.launch.py` chạy `slam_toolbox` (`async_slam_toolbox_node`, chế độ `mapping`, có loop closing) với `atlas_slam_toolbox.yaml`. Bản đồ lưu vào `src/c1_maps/` (đã có `map1/`, `map2/`).
- **Localization**: `atlas_map_server_real.launch.py` chạy `map_server` + `map_saver` + **AMCL** + `lifecycle_manager`. (slam_toolbox chế độ localization có tồn tại trong code nhưng đang bị **comment out**, xem [Vấn đề đã biết](#vấn-đề-đã-biết--hạn-chế)).
- **Navigation**: `atlas_navigation_real.launch.py` chạy đầy đủ chồng Nav2 với `atlas_nav2_mppi.yaml`: `planner_server` (**NavFn**), `controller_server` (**MPPI**), `smoother_server` (SimpleSmoother), `bt_navigator`, `behavior_server`, `velocity_smoother`, `collision_monitor`, `waypoint_follower`, dưới 1 `lifecycle_manager_navigation`. Costmap: `obstacle_layer` + `voxel_layer` (laser) + `keepout_filter` + `inflation_layer` (local); `static_layer` + `speed_filter` (global).
- **Collision monitor** (`atlas_collision_monitor.yaml`): `PolygonStop`/`PolygonSlow`/`FootprintApproach` dùng `/atlas/scan_filtered`; nguồn pointcloud (RealSense) khai báo nhưng `enabled: false`; `PolygonLimit`/`VelocityPolygonStop` cũng tắt (ghi chú "chưa hỗ trợ trên ROS 2 Humble").
- **Alternative/thử nghiệm, chưa nằm trong quy trình chính thức** (`docs/run_robot.md` không nhắc tới): `atlas_cartographer_real.launch.py` (mapping bằng `cartographer_ros` thay vì slam_toolbox), `atlas_nav2_dwb.yaml` (config DWB không được launch file nào tham chiếu), `scripts/route_manager.py`/`route_tool.py` (GUI PyQt5 vẽ tuyến điểm waypoint, gửi qua Nav2 action `FollowWaypoints`).

### `ESP32_code` (firmware, PlatformIO)
- `src/main.cpp` là entrypoint thật: đọc encoder 4 bánh bằng PCNT (pulse counter) của ESP32, chạy **PID tốc độ từng bánh cục bộ** (so target RPM từ ROS với tốc độ đo được), xuất PWM 2 kênh/động cơ (H-bridge).
- Giao thức serial: class `CanSerial` (đặt tên gợi nhớ CAN nhưng thực chất chỉ là **serial framing**, cùng format `0x2a...0x23` với `ros_serial_bridge.py` bên ROS) — không dùng bus CAN thật.
- Gửi encoder-tick về ROS đang bị **comment out hoàn toàn** — khớp với việc `Velinfo.msg` không được dùng ở phía ROS: hiện KHÔNG có đường truyền phản hồi (feedback) tốc độ bánh thật về ROS.
- Repo còn nhiều file legacy không được `main.cpp` include (`CAN.c`, `CAN_manager.cpp`, `ESP32CAN.cpp`, `Main_controller.cpp`, `OC_controller.h`, `hardwareconfig.h`, `controll_config.h` — có cả SSID Wi-Fi, RFID ID của project mẫu khác) — code chết, nên dọn hoặc đánh dấu rõ khi đọc.

---

## Thuật toán sử dụng

| Thuật toán | Ở đâu | Vai trò |
|---|---|---|
| **Động học nghịch mecanum** (ma trận 4×3: `[1,-1,-k; 1,1,k; 1,1,-k; 1,-1,k]`, `k = lx+ly`) | `c1_driver/kinematic.py`, `c1_description/mecanum_joint_publisher.py` | Chuyển `Twist` (vx, vy, ω) → RPM từng bánh |
| **PID vòng tốc độ (closed-loop)** | ESP32 firmware (`main.cpp`) | Bám tốc độ bánh mục tiêu dựa trên encoder, chạy hoàn toàn local trên vi điều khiển |
| **Range-flow scan matching odometry** | `rf2o_laser_odometry` | Ước lượng vận tốc/odometry từ 2 scan laser liên tiếp, không cần encoder |
| **SLAM dựa pose-graph (Karto, qua slam_toolbox)** | `atlas_slam_toolbox_real.launch.py` | Lập bản đồ (mapping) kèm loop closing |
| **AMCL (Adaptive Monte Carlo Localization)** | `atlas_map_server_real.launch.py` | Định vị robot trên bản đồ đã lưu (particle filter) |
| **MPPI (Model Predictive Path Integral)** | Nav2 `controller_server`, `atlas_nav2_mppi.yaml` | Bộ điều khiển bám quỹ đạo / tránh vật cản cục bộ |
| **NavFn (Dijkstra/A\* trên costmap)** | Nav2 `planner_server` | Lập kế hoạch đường đi toàn cục |
| **Behavior Tree navigation** | Nav2 `bt_navigator` | Điều phối trạng thái nhiệm vụ điều hướng (recovery, waypoint...) |
| **Priority-based topic arbitration** | `twist_mux` | Chọn nguồn `cmd_vel` (nav/joystick/lateral) theo độ ưu tiên + timeout |
| **Debounce theo cửa sổ thời gian** | `lateral_teleop_node.py` | Lọc nhiễu tín hiệu nút bấm rời rạc trên joystick |

---

## Cài đặt & build

Yêu cầu: **Ubuntu 22.04 + ROS 2 Humble**, đã cài `joy`, `teleop_twist_joy`, `twist_mux`, `topic_tools`, `nav2_bringup` (và các gói Nav2 liên quan), `slam_toolbox`, `nav2_amcl`.

```bash
cd ~/atlas_c1
colcon build --symlink-install
source install/setup.bash
```

Cấu hình cổng serial một lần (theo `docs/dev_port.md`): tạo udev rule để `/dev/esp32` và `/dev/ydlidar` là symlink cố định theo cổng USB vật lý, tránh việc tên `/dev/ttyUSBx` đổi lộn xộn giữa các lần cắm lại.

---

## Vận hành

Quy trình đầy đủ nằm ở [`docs/run_robot.md`](docs/run_robot.md), tóm tắt:

**Trên robot:**
```bash
ros2 launch c1_bringup c1_bringup_robot.launch.py
```

**Trên PC — Mapping:**
```bash
ros2 launch c1_bringup c1_bringup_pc.launch.py
ros2 launch atlas_slam atlas_slam_toolbox_real.launch.py
# lưu bản đồ vào src/c1_maps/, rồi Ctrl+C
```

**Trên PC — Navigation:**
```bash
ros2 launch c1_bringup c1_bringup_pc.launch.py     # bỏ qua nếu vẫn đang chạy từ bước mapping
ros2 launch atlas_slam atlas_map_server_real.launch.py map:=/duong/dan/toi/map1.yaml
# dùng '2D Pose Estimate' trên RViz để định vị ban đầu
ros2 launch atlas_slam atlas_navigation_real.launch.py
# dùng 'Nav2 Goal' để ra lệnh di chuyển
```

---

## Vấn đề đã biết / hạn chế

Các điểm sau là trạng thái **thật** của code, nên biết trước khi dựa vào:

1. **`atlas_map_server_real.launch.py` bị lỗi tham số**: file params khai báo là `atlas_localization.yaml` nhưng file thật trên đĩa tên `atlas_localization_c1.yaml` — launch với tên cũ sẽ không load được tham số như ý. Map mặc định trỏ `src/atlas_maps/map7/map7.yaml` (không tồn tại) trong khi map thật nằm ở `src/c1_maps/map1/`.
2. **Localization dùng AMCL, không phải slam_toolbox** dù file `atlas_localization_c1.yaml` chỉ có phần tham số cho `slam_toolbox` (không có mục `amcl:`) — nghĩa là AMCL hiện chạy gần như bằng tham số mặc định, chưa được tune theo file này.
3. **`twist_mux` không nhận được lệnh Nav2**: Nav2/collision_monitor xuất `cmd_vel` thẳng ra topic `/cmd_vel`, trong khi `twist_mux` lại lắng nghe nhánh "navigation" ở topic `cmd_vel_nav` — không có node nào publish `cmd_vel_nav`. Nếu chạy đồng thời cả Nav2 và joystick, cả hai có thể ghi đè trực tiếp lên `/cmd_vel`.
4. **Không có phản hồi (feedback) tốc độ bánh thật về ROS**: `Velinfo.msg` và đoạn gửi encoder-tick trong firmware ESP32 đều tồn tại nhưng không được dùng/bị comment — PID chạy kín hoàn toàn trên ESP32, ROS không biết tốc độ bánh thực tế.
5. **Thông số động học không khớp giữa các package**: `kinematic.py` dùng `r=0.035, lx=0.085, ly=0.11`; `c1_description`/`mecanum_joint_publisher.py` dùng `R=0.049, Lx=0.11, Ly=0.15`. Cần đối chiếu với kích thước robot thật để thống nhất.
6. **Nav2 đang điều khiển robot như diff-drive**: cả `atlas_nav2_mppi.yaml` và `atlas_nav2_dwb.yaml` đặt `motion_model: DiffDrive` và khoá `vy_max/max_vel_y = 0` — dù phần cứng (mecanum) và `lateral_teleop_node.py` đều hỗ trợ đi ngang, Nav2 hiện chưa khai thác khả năng holonomic này.
7. **Cảm biến RealSense được cấu hình nhưng không tồn tại**: costmap toàn cục và collision monitor có khai báo nguồn pointcloud từ `/intel_realsense_r200_depth/points`, nhưng URDF (`c1_description`) không có camera nào — coi đây là phần cứng dự kiến trong tương lai, chưa lắp.
8. **Code thừa/không dùng**: `c1_platform` là package rỗng; submodule `src/atlas_base` không được checkout; `ESP32_code` còn nhiều file CAN-bus/RFID/UDP-debug từ template dự án khác, không được `main.cpp` include; `atlas_nav2_dwb.yaml` không launch file nào tham chiếu; `atlas_cartographer_real.launch.py` và `route_manager.py`/`route_tool.py` là công cụ thử nghiệm, không nằm trong quy trình chính thức ở `docs/run_robot.md`.
