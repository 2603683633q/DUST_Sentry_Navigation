from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument
from launch_ros.substitutions import FindPackageShare
import os

def generate_launch_description():
    # 声明参数
    xfer_format_arg = DeclareLaunchArgument('xfer_format', default_value='0')
    multi_topic_arg = DeclareLaunchArgument('multi_topic', default_value='0')
    data_src_arg = DeclareLaunchArgument('data_src', default_value='0')
    publish_freq_arg = DeclareLaunchArgument('publish_freq', default_value='10.0')
    output_data_type_arg = DeclareLaunchArgument('output_data_type', default_value='0')
    lvx_file_path_arg = DeclareLaunchArgument('lvx_file_path', default_value='')
    user_config_path_arg = DeclareLaunchArgument(
        'user_config_path',
        default_value=os.path.join(
            FindPackageShare('livox_ros2_driver').find('livox_ros2_driver'),
            'config/livox_lidar_config.json'
        )
    )
    cmdline_input_bd_code_arg = DeclareLaunchArgument('cmdline_input_bd_code')
    frame_id_arg = DeclareLaunchArgument('frame_id', default_value='livox_frame')

    # LiDAR 节点
    livox_node = Node(
        package='livox_ros2_driver',
        executable='livox_ros2_driver_node',
        name='livox_ros2_driver',
        output='screen',
        remappings=[
            ('/livox/lidar', '/livox/Horizon_lidar'),
            ('/livox/imu', '/livox/Horizon_imu'),
        ],
        parameters=[{
            'xfer_format': LaunchConfiguration('xfer_format'),
            'multi_topic': LaunchConfiguration('multi_topic'),
            'data_src': LaunchConfiguration('data_src'),
            'publish_freq': LaunchConfiguration('publish_freq'),
            'output_data_type': LaunchConfiguration('output_data_type'),
            'lvx_file_path': LaunchConfiguration('lvx_file_path'),
            'user_config_path': LaunchConfiguration('user_config_path'),
            'cmdline_input_bd_code': LaunchConfiguration('cmdline_input_bd_code'),
            'frame_id': LaunchConfiguration('frame_id'),
        }]
    )

    # RViz 节点
    # rviz_config_file = os.path.join(
    #     FindPackageShare('livox_ros2_driver').find('livox_ros2_driver'),
    #     '/home/rmsentry/CSU-RM-Sentry/src/rm_hardware_driver/livox_ros2_driver/livox_ros2_driver/config/display_point_cloud.rviz'  # 你可以换成自己的 rviz 配置文件
    # )
    # rviz_node = Node(
    #     package='rviz2',
    #     executable='rviz2',
    #     name='rviz2',
    #     output='screen',
    #     arguments=['-d', rviz_config_file],
    # )

    return LaunchDescription([
        xfer_format_arg,
        multi_topic_arg,
        data_src_arg,
        publish_freq_arg,
        output_data_type_arg,
        lvx_file_path_arg,
        user_config_path_arg,
        cmdline_input_bd_code_arg,
        frame_id_arg,
        livox_node,
        #rviz_node
    ])
