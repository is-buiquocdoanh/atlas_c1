import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node


def generate_launch_description():

    bringup_dir = get_package_share_directory('c1_bringup')
    devices_config = os.path.join(bringup_dir, 'config', 'devices.yaml')

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
    # Joystick 
    joy_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('c1_bringup'), 'launch', 'joystick.launch.py')
        )
    )



    
    return LaunchDescription([
  
        ros_serial_bridge,
        kinematic_node,
        joy_launch,

    ])
