import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    package_dir = get_package_share_directory('atlas_slam')
    launch_dir = os.path.join(package_dir, 'launch')
    workspace_dir = os.path.abspath(os.path.join(package_dir, '..', '..', '..', '..'))
    maps_dir = os.path.join(workspace_dir, 'src', 'atlas_maps')

    map_yaml_arg = DeclareLaunchArgument(
        'map',
        default_value=os.path.join(maps_dir, 'map1', 'map1.yaml'),
        description='Full path to the YAML map file to load'
    )

    map_server_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(launch_dir, 'atlas_map_server_real.launch.py')
        ),
        launch_arguments={'map': LaunchConfiguration('map')}.items()
    )

    navigation_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(launch_dir, 'atlas_navigation_real.launch.py')
        )
    )

    return LaunchDescription([
        map_yaml_arg,
        map_server_launch,
        navigation_launch,
    ])
