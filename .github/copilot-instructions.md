# AI Coding Agent Instructions - pb2025_sentry_nav

A ROS 2 (Humble) navigation system for RoboMaster 2025 Sentry robot, built on NAV2 framework with advanced coordinate transformation handling and LiDAR-based SLAM.

## Project Architecture

### Core Components
- **Robot Description** (`pb2025_robot_description`): XMacro-based robot URDF/SDF generation with industrial camera and Livox mid360 LiDAR
- **Navigation Stack** (`pb2025_nav_bringup`): NAV2 bringup with custom plugins and controllers
- **Odometry Pipeline**: point_lio (SLAM) → loam_interface → sensor_scan_generation (coordinate transforms)
- **Path Following**: pb_omni_pid_pursuit_controller (pursuer-pursuer with omnidirectional support)
- **Relocalization**: small_gicp_relocalization for global position recovery
- **Gazebo Simulator** (`rmu_gazebo_simulator`): Ignition Gazebo with RM-specific models and plugins

### Critical Coordinate System Design
The system uses an implicit 2-frame architecture addressing LiDAR-Odometry offset:
- **`lidar_odom`**: point_lio origin (from cloud_registered output)
- **`odom`**: chassis origin (standard ROS frame)
- **`loam_interface`**: Transforms cloud_registered from `lidar_odom` → `odom`
- **`sensor_scan_generation`**: Converts point clouds and publishes `odom → chassis` transform
- **`front_mid360`**: LiDAR frame (tilted side-mount on chassis)

*Reference: `frames_2025-12-16_03.01.47.gv` shows full TF tree*

### Multi-Robot Namespace Pattern
All nodes, topics, and actions use namespace prefixes (e.g., `/red_standard_robot1`) for multi-robot extension. 
Verify TF trees with: `ros2 run rqt_tf_tree rqt_tf_tree --ros-args -r /tf:=tf -r /tf_static:=tf_static -r __ns:=/red_standard_robot1`

## Build & Execution

### Quick Build
```bash
cd ~/ros_ws
rosdep install -r --from-paths src --ignore-src --rosdistro humble -y
colcon build --symlink-install
```

### Key Packages by Build Type
- **ament_cmake**: pb2025_robot_description, pb_omni_pid_pursuit_controller, point_lio, small_gicp
- **ament_python**: pb2025_nav_bringup, fake_vel_transform, ign_sim_pointcloud_tool, loam_interface

### Critical Commands
```bash
# Source workspace (required before any ros2 commands)
source install/setup.bash

# Gazebo simulation
ros2 launch rmu_gazebo_simulator gazebo.launch.py

# Robot visualization
ros2 launch pb2025_robot_description robot_description_launch.py

# Full navigation stack (simulator)
ros2 launch pb2025_nav_bringup bringup_sim.launch.py namespace:=/red_standard_robot1

# Real robot with auto TF tree (gimbal_joint_publisher subscribes to /serial/gimbal_joint_state)
ros2 launch pb2025_nav_bringup rm_navigation_reality_launch.py \
  slam:=True \
  use_robot_state_pub:=False
```

### Auto TF Tree from Gimbal Status (Real Robot)
When `use_robot_state_pub:=False`, the following chain handles gimbal joint updates automatically:
1. **gimbal_joint_publisher**: Subscribes to `/serial/gimbal_joint_state` (sensor_msgs/JointState)
2. **Robot State Publisher**: Reads URDF and converts joint states to TF tree
3. **TF Broadcaster**: Publishes TF tree (`odom → chassis → gimbal_yaw → gimbal_pitch → sensors`)

The gimbal state message from serial driver contains:
```python
# sensor_msgs/JointState message from serial/gimbal_joint_state
name: ['gimbal_yaw', 'gimbal_pitch']
position: [yaw_rad, pitch_rad]      # Gimbal angles in radians
velocity: [yaw_vel, pitch_vel]      # Gimbal velocities in rad/s
effort: [0.0, 0.0]                  # Forces/torques
```

#### Implementation Details
- Node: `src/pb2025_sentry_nav/pb2025_nav_bringup/scripts/gimbal_joint_publisher.py`
- Subscribe: `/serial/gimbal_joint_state` → Publish: `/joint_states`
- Performs joint name mapping: `gimbal_yaw` → `gimbal_yaw_joint`, `gimbal_pitch` → `gimbal_pitch_joint`
- Supports multi-robot namespaces automatically
- Full documentation: `src/pb2025_sentry_nav/pb2025_nav_bringup/GIMBAL_JOINT_PUBLISHER.md`

### Build Flags & Dependencies
- Release mode recommended: `colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release` (point_lio, small_gicp)
- External: Install small_gicp via: `git clone https://github.com/koide3/small_gicp && cmake -DCMAKE_BUILD_TYPE=Release && make install`
- XMacro generation requires: `pip install xmacro`

## Code Patterns & Conventions

### Python Launch Files Pattern
Launch files use `OpaqueFunction` to evaluate launch arguments at runtime and access `LaunchContext`:
- Always import: `from launch import LaunchContext, LaunchDescription` and `from launch.actions import OpaqueFunction`
- Define setup function: `def launch_setup(context: LaunchContext) -> list:`
- Retrieve configs via: `LaunchConfiguration("param_name").perform(context)` inside setup
- Example: pb2025_robot_description/launch/robot_description_launch.py

### Robot Description via XMacro
- Define structures in: `resource/xmacro/*.sdf.xmacro`
- Load in Python: `XMLMacro4sdf()` → `parse_from_sdf_string()` → URDF conversion via `UrdfGenerator`
- Example: pb2025_robot_description/launch/robot_description_launch.py generates URDF/SDF from xmacro dynamically
- Mesh scaling workaround: horizon.dae requires explicit `scale="0.001 0.001 0.001"` injection in URDF

### Node Namespace Conventions
All nodes receive namespace from launch arguments and prepend to topics:
```python
Node(
    namespace=LaunchConfiguration("namespace"),
    name="node_name",
    # topics will be: /namespace/topic_name
)
```

### Configuration via YAML
- Config files stored in `config/` directories
- Loaded via `ParameterFile()` or direct YAML parsing with `nav2_common.launch.RewrittenYaml`
- Pattern: wrap YAML with param substitutions like `use_sim_time` before passing to Node

### Python Nodes with ROS 2
- Use `rclpy.Node` base class; `__init__` super calls with node name
- Always use `self.create_subscription()` and `self.create_publisher()` for pub/sub
- Joint state publishing pattern: subscribe to sensor input, publish `sensor_msgs/JointState` with name/position arrays
- Example: gimbal_joint_publisher.py in pb2025_nav_bringup/scripts/

## Integration Points & Dependencies

### External ROS 2 Packages
- **nav2_core, nav2_common**: Bringup utilities, LaunchConfiguration helpers, parameter generation
- **launch_ros**: Node/Parameter/LifecycleNode actions; ROS-specific launch utilities
- **robot_state_publisher**: Publishes TF tree from URDF
- **rclpy**: Python ROS 2 client library (used in Python nodes)
- **rmoss_interfaces, pb_rm_interfaces**: Custom message definitions for RM robots

### Point Cloud Pipeline
1. **point_lio** (SLAM): Outputs `cloud_registered` in `lidar_odom` frame
2. **loam_interface**: Subscribes to `cloud_registered`, transforms to `odom`, republishes
3. **sensor_scan_generation**: Converts point clouds to LaserScan; handles TF lookups
4. **terrain_analysis**: Computes ground height per-point (intensity field), 4m range
5. **pointcloud_to_laserscan**: Bridges obstacles terrain data to LaserScan for costmap

### Gazebo-Specific Tools
- **ign_sim_pointcloud_tool**: Adds missing `time` field to simulated point clouds (point_lio requires it)
- **Gazebo Plugins** (`rmoss_gz_plugins`): Custom physics, sensors for RM simulation
- **rmu_gazebo_simulator**: Ignition Gazebo launch with RM arena/robot models

## Debugging & Common Issues

### Coordinate Transform Problems
- Use `ros2 run tf2_tools view_frames` to check TF tree
- Check frame hierarchy: `lidar_odom` → `odom` → `chassis` → sensor frames
- Verify `loam_interface` publishing odom frame at 10 Hz
- For LiDAR data: Ensure `sensor_scan_generation` receiving point clouds in `odom` frame
- Multi-robot: verify all nodes inherit correct namespace (check with `ros2 node list`)

### Simulation Point Cloud Issues
- point_lio fails in sim because Gazebo PointCloud lacks `time` field → use `ign_sim_pointcloud_tool` preprocessing
- Verify field structure: check point_lio README for exact field requirements

### Launch File Issues
- Use `use_sim_time:=True` in simulator to sync clock with Gazebo
- Check conditional launches with `IfCondition()` for `use_robot_state_pub` flag
- Namespace substitution: use `TextSubstitution` for string prepending in remappings

## Testing & Validation

### Pre-Commit Hooks
Enabled: ament_lint_auto, ament_lint_common, ament_cmake_clang_format, ament_cmake_black
- Automatically runs on commit; use `pre-commit run --all-files` locally first

### Key Test Commands
```bash
# Lint check
colcon test --packages-select <package> --ctest-args --output-on-failure

# Specific node test
ros2 launch <package> <launch_file>.py <args>
```

## Documentation References
- [NAV2 Navigation Framework](https://github.com/ros-navigation/navigation2)
- [pb2025_sentry_nav](https://github.com/SMBU-PolarBear-Robotics-Team/pb2025_sentry_nav): Main project README for detailed component descriptions
- pb2025_robot_description: URDF/SDF generation with xmacro (README.md in src/pb2025_robot_description/)
- point_lio: SLAM algorithm details and field requirements (README.md in src/pb2025_sentry_nav/point_lio/)
- small_gicp_relocalization: Global relocalization (README.md in src/pb2025_sentry_nav/small_gicp_relocalization/)
- GIMBAL_JOINT_PUBLISHER.md: Auto TF tree from gimbal status (in src/pb2025_sentry_nav/pb2025_nav_bringup/)
