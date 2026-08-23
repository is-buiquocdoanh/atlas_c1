## Robot
### SSH vào robot
Kết nối vào wifi của robot:
- User: Atlas_c1
- Password: 12345678
```
ssh nuc@192.168.9.199
```

### Khởi chạy phần cứng trên robot
```
ros2 launch c1_bringup c1_bringup_robot.launch.py 
```

## Trên PC
### Tạo bản đồ (mapping)
1. Khởi chạy bringup trên PC
```
ros2 launch c1_bringup c1_bringup_pc.launch.py 
```
2. Khởi chạy mapping
```
ros2 launch atlas_slam atlas_slam_toolbox_real.launch.py 
```
- Sau đó lưu bản đồ  vào src/c1_maps
- Lưu xong bản đồ thì ctrl C để tắt chương trình mapping để chuyển sang navigation

### Điều hướng đến đích (Navigation)
1. Khởi chạy bringup trên PC
```
ros2 launch c1_bringup c1_bringup_pc.launch.py 
```
- Lưu ý: nếu chương trình này vẫn còn chạy trên mapping thì không cần chạy lại

2. Khởi chạy map server
```
ros2 launch atlas_slam atlas_map_server_real.launch.py map:=/home/doanh/atlas_c1/src/c1_maps/map1/map1.yaml
```
- Lưu ý: thay đường dẫn map:= (bằng đường dẫn map thực tế của bạn)
- Sau đó trên rviz2 sử dụng tool '2D pose estimate' để định vị vị trí ban đầu cho robot

3. Khởi chạy navigation
```
ros2 launch atlas_slam atlas_navigation_real.launch.py 
```
- Sử dụng tool goal pose để set vị trí muốn đến trên map