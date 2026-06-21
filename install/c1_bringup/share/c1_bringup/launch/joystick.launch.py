from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument

import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    use_sim_time = LaunchConfiguration('use_sim_time')

    joy_params = os.path.join(get_package_share_directory('c1_bringup'), 'config', 'joystick.yaml')

    # Node đọc tay cầm và xuất /joy
    joy_node = Node(
            package='joy',
            executable='joy_node',
         )
    # Node chuyển /joy -> /cmd_vel_joy
    teleop_node = Node(
            package='teleop_twist_joy',
            executable='teleop_node',
            name='teleop_node',
            parameters=[joy_params],
            remappings=[('/cmd_vel','/cmd_vel_joy')]
         )

    # Node mux các lệnh /cmd_vel_* thành /cmd_vel
    twist_mux_node = Node(
            package='twist_mux',
            executable='twist_mux',
            name='twist_mux',
            output='screen',
            parameters=[joy_params],
            remappings=[('/cmd_vel_out', '/cmd_vel')]  # output cuối cùng ra /cmd_vel
    )

    return LaunchDescription([
        joy_node,
        teleop_node,
        twist_mux_node
    ])