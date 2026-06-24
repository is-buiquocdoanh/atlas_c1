import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import LifecycleNode, Node


def generate_launch_description():

    bringup_dir = get_package_share_directory('c1_bringup')
    devices_config = os.path.join(bringup_dir, 'config', 'devices.yaml')

    # robot description
    display = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('c1_description'), 'launch', 'display.launch.py')
        )
    )

    # YDLidar TG30 (ydlidar.yaml gốc + devices.yaml override port)
    ydlidar_node = LifecycleNode(
        package='ydlidar_ros2_driver',
        executable='ydlidar_ros2_driver_node',
        name='ydlidar_ros2_driver_node',
        output='screen',
        emulate_tty=True,
        parameters=[devices_config],
        namespace='/',
    )

    # C1 DRIVER
    # Ros serial brigde
    ros_serial_bridge = Node(
        package = 'c1_driver',
        executable = 'ros_serial_bridge.py',
        name = 'ros_serial_bridge',
        output = 'screen',
        parameters=[devices_config]
    )
    
    # Kinematic
    kinematic_node = Node(
        package='c1_driver',
        executable='kinematic.py',
        name='kinematic',
        output='screen',
    )
    



    # Relay /scan → /atlas/scan_filtered
    scan_relay = Node(
        package='topic_tools',
        executable='relay',
        name='scan_relay',
        parameters=[{
            'input_topic':  '/scan',
            'output_topic': '/atlas/scan_filtered',
        }],
    )

    # RF2O Laser Odometry
    rf2o_node = Node(
            package='rf2o_laser_odometry',
            executable='rf2o_laser_odometry_node',
            name='rf2o_laser_odometry',
            output='screen',
            parameters=[{
                'laser_scan_topic': '/atlas/scan_filtered',
                'odom_topic': '/atlas/odom', # có thể sử dụng /odom_rf2o
                'publish_tf': True,
                'base_frame_id': 'base_link',
                'odom_frame_id': 'odom',
                'init_pose_from_topic': '',
                'freq': 30.0
            }],
        )
    
    # Joystick 
    joy_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('c1_bringup'), 'launch', 'joystick.launch.py')
        )
    )
    
    # API
    api_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('atlas_api'), 'launch', 'atlas_api_real.launch.py')
        )
    )

    # app PC
    app_pc_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('atlas_app'), 'launch', 'atlas_app.launch.py')
        )
    )
    
    return LaunchDescription([
        # laser_tf,
        display,
        # ydlidar_node,
        # ros_serial_bridge,
        # kinematic_node,
        scan_relay,
        rf2o_node,
        joy_launch,
        # api_launch,
        # app_pc_launch,

    ])
