import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, OpaqueFunction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def launch_setup(context, *args, **kwargs):

    bringup_dir = get_package_share_directory('c1_bringup')
    devices_config = os.path.join(bringup_dir, 'config', 'devices.yaml')

    # Port truyền qua launch argument sẽ ghi đè serial_port trong devices.yaml
    serial_params = [devices_config]
    port = LaunchConfiguration('port').perform(context)
    if port:
        serial_params.append({'serial_port': port})

    # C1 DRIVER
    # Ros serial brigde
    ros_serial_bridge = Node(
        package = 'c1_driver',
        executable = 'ros_serial_bridge.py',
        name = 'ros_serial_bridge',
        output = 'screen',
        parameters=serial_params
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

    return [
        ros_serial_bridge,
        kinematic_node,
        # joy_launch,
    ]


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'port',
            default_value='',
            description='Serial port của ESP32 (mặc định lấy từ config/devices.yaml)'
        ),
        OpaqueFunction(function=launch_setup),
    ])
