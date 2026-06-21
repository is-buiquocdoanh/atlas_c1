import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    urdf_file = os.path.join(
        get_package_share_directory('c1_description'), 'urdf', 'c1_robot.urdf'
    )
    robot_description = open(urdf_file).read()

    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': robot_description}],
    )

    joint_state_publisher_gui = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
    )

    mecanum_joint_publisher = Node(
        package='c1_description',
        executable='mecanum_joint_publisher.py',
        name='mecanum_joint_publisher',
        output='screen',
    )

    rviz2 = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', os.path.join(
            get_package_share_directory('c1_description'), 'rviz', 'display.rviz'
        )],
    )

    return LaunchDescription([
        robot_state_publisher,
        mecanum_joint_publisher,
        # joint_state_publisher_gui,
        # rviz2,
    ])
