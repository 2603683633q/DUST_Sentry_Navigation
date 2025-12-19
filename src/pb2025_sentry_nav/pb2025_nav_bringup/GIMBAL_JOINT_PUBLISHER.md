# Gimbal Joint Publisher - 云台关节状态发布器

## 概述

`gimbal_joint_publisher` 是一个 ROS 2 节点，用于订阅来自串口驱动的云台状态话题 (`/serial/gimbal_status`)，并将其转换为标准的 `JointState` 消息。这使得 `joint_state_publisher` 和 `robot_state_publisher` 能够自动建立机器人的 TF 树。

## 使用场景

当使用命令：
```bash
ros2 launch pb2025_nav_bringup rm_navigation_reality_launch.py \
  slam:=True \
  use_robot_state_pub:=False
```

此时：
- `use_robot_state_pub:=False` 禁用独立的 robot_state_publisher 启动文件
- `gimbal_joint_publisher` 自动启动，订阅 `/serial/gimbal_status`
- `joint_state_publisher` 订阅所有 `joint_states` 并聚合它们
- `robot_state_publisher` 发布 TF 树和 `/tf_static` 链接

## 数据流

```
Serial Driver
    ↓
/serial/gimbal_status (pb_rm_interfaces/Gimbal)
    ↓
gimbal_joint_publisher (本节点)
    ↓
/joint_states (sensor_msgs/JointState)
    ↓
joint_state_publisher + robot_state_publisher
    ↓
TF Tree (odom → chassis → gimbal_yaw → gimbal_pitch)
```

## 节点详情

### 订阅话题

- **`/serial/gimbal_status`** (pb_rm_interfaces/Gimbal)
  - `yaw` (float32): 云台 yaw 轴角度，单位：弧度
  - `pitch` (float32): 云台 pitch 轴角度，单位：弧度

### 发布话题

- **`/joint_states`** (sensor_msgs/JointState)
  - `header.stamp`: 消息时间戳
  - `name`: `['gimbal_yaw_joint', 'gimbal_pitch_joint']`
  - `position`: `[yaw_angle, pitch_angle]`（单位：弧度）
  - `velocity`: `[0.0, 0.0]`（未提供）
  - `effort`: `[0.0, 0.0]`（未提供）

### 参数

- **`namespace`** (string, default: "")
  - 节点的 ROS 命名空间前缀，用于多机器人支持

## 关键配置

### 机器人描述中的关节定义

机器人的关节必须在 URDF/SDF 中定义，关节名称必须精确匹配：

```sdf
<!-- 在 pb2025_sentry_robot.sdf.xmacro 中 -->
<joint name="gimbal_yaw_joint" type="revolute">
  ...
</joint>

<joint name="gimbal_pitch_joint" type="revolute">
  ...
</joint>
```

### Launch 文件配置

在 `rm_navigation_reality_launch.py` 中自动启动三个节点：

```python
# 云台关节发布器（订阅云台状态）
gimbal_joint_publisher_node = Node(
    package="pb2025_nav_bringup",
    executable="gimbal_joint_publisher.py",
    name="gimbal_joint_publisher",
    output="screen",
    namespace=namespace,
)

# 关节状态发布器（仅在 use_robot_state_pub=False 时启动）
joint_state_publisher_node = Node(
    package="joint_state_publisher",
    executable="joint_state_publisher",
    name="joint_state_publisher",
    output="screen",
    namespace=namespace,
    condition=~IfCondition(use_robot_state_pub),
)

# 机器人状态发布器（仅在 use_robot_state_pub=False 时启动）
robot_state_publisher_node = Node(
    package="robot_state_publisher",
    executable="robot_state_publisher",
    name="robot_state_publisher",
    output="screen",
    namespace=namespace,
    parameters=[{"use_sim_time": use_sim_time}],
    condition=~IfCondition(use_robot_state_pub),
)
```

## 故障排查

### 症状：TF 树中没有云台关节

**原因：** gimbal_status 话题未发送

**解决方案：**
```bash
# 检查话题是否存在
ros2 topic list | grep gimbal_status

# 检查是否有消息发送
ros2 topic echo /serial/gimbal_status

# 检查云台关节发布器是否运行
ros2 node list | grep gimbal_joint_publisher
```

### 症状：收到错误 "Cannot find gimbal_joint_publisher"

**原因：** 包未编译或脚本不在预期位置

**解决方案：**
```bash
# 重新编译
cd ~/ros_ws
colcon build --packages-select pb2025_nav_bringup
source install/setup.bash
```

### 症状：Joint state 消息中没有云台关节

**原因：** gimbal_joint_publisher 发布失败

**检查：**
```bash
# 检查 joint_states 话题中的内容
ros2 topic echo /joint_states

# 查看节点输出
ros2 launch ... &  # 启动后在另一个终端
ros2 node info /gimbal_joint_publisher
```

## 与 robot_state_publisher 的关系

### 当 use_robot_state_pub=True（默认）
- 启用独立的 `robot_state_publisher` 启动文件
- 该启动文件包含 `robot_description_launch.py`
- 云台状态可来自其他来源（如仿真环境的 Gazebo 插件）
- 不依赖 gimbal_joint_publisher

### 当 use_robot_state_pub=False（实车模式）
- 禁用独立的 robot_state_publisher 启动文件
- gimbal_joint_publisher + joint_state_publisher + robot_state_publisher 组成完整链
- 云台状态直接来自串口驱动的 `/serial/gimbal_status`

## 多机器人支持

节点支持多机器人命名空间。启动时指定命名空间：

```bash
ros2 launch pb2025_nav_bringup rm_navigation_reality_launch.py \
  namespace:=/red_standard_robot1 \
  slam:=True \
  use_robot_state_pub:=False
```

此时所有话题和节点都会带有 `/red_standard_robot1` 前缀：
- Node: `/red_standard_robot1/gimbal_joint_publisher`
- Topic: `/red_standard_robot1/joint_states`
- Topic: `/red_standard_robot1/serial/gimbal_status`

## 依赖包

- `rclpy`: ROS 2 Python 客户端库
- `sensor_msgs`: JointState 消息定义
- `pb_rm_interfaces`: Gimbal 消息定义
- `joint_state_publisher`: 聚合 joint_states
- `robot_state_publisher`: 发布 TF 树

## 源代码位置

- 节点脚本: `src/pb2025_sentry_nav/pb2025_nav_bringup/scripts/gimbal_joint_publisher.py`
- Launch 文件: `src/pb2025_sentry_nav/pb2025_nav_bringup/launch/rm_navigation_reality_launch.py`
