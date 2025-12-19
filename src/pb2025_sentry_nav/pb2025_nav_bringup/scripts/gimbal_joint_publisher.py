#!/usr/bin/env python3
"""
云台关节状态发布器
订阅 /serial/gimbal_joint_state 话题，转换并发布 joint_states 供 robot_state_publisher 建立 TF 树
支持多机器人命名空间
"""
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState


class GimbalJointPublisher(Node):
    def __init__(self):
        super().__init__('gimbal_joint_publisher')
        
        # 声明和获取 namespace 参数
        self.declare_parameter('namespace', '')
        namespace = self.get_parameter('namespace').value
        
        # 创建 joint_states 发布器 (供 robot_state_publisher 使用)
        self.joint_state_pub = self.create_publisher(
            JointState, 
            'joint_states',
            10
        )
        
        # 订阅云台状态 (来自串口驱动)
        # 来源：rm_serial_driver 或其他串口驱动发布的云台关节状态
        self.gimbal_joint_state_sub = self.create_subscription(
            JointState,
            'serial/gimbal_joint_state',
            self.gimbal_joint_state_callback,
            10
        )
        
        # 关节名称映射：从 serial/gimbal_joint_state 的名称映射到 URDF 中的名称
        # serial topic: gimbal_yaw, gimbal_pitch
        # URDF names: gimbal_yaw_joint, gimbal_pitch_joint
        self.joint_name_mapping = {
            'gimbal_yaw': 'gimbal_yaw_joint',
            'gimbal_pitch': 'gimbal_pitch_joint'
        }
        
        self.get_logger().info(
            f'GimbalJointPublisher initialized (namespace: {namespace or "default"})'
        )
        
    def gimbal_joint_state_callback(self, msg: JointState):
        """
        处理云台关节状态消息，转换关节名称并重新发布
        
        Args:
            msg: sensor_msgs/JointState 消息 (来自 serial/gimbal_joint_state)
                - name: ['gimbal_yaw', 'gimbal_pitch']
                - position: 各关节角度 (rad)
                - velocity: 各关节速度 (rad/s)
                - effort: 各关节力矩 (N·m)
        """
        # 创建新的 JointState 消息，转换关节名称
        joint_state = JointState()
        joint_state.header = msg.header
        
        # 转换关节名称：使用 URDF 中定义的名称
        joint_state.name = []
        joint_state.position = []
        joint_state.velocity = []
        joint_state.effort = []
        
        for i, joint_name in enumerate(msg.name):
            # 使用映射表转换关节名称
            urdf_joint_name = self.joint_name_mapping.get(joint_name, joint_name)
            joint_state.name.append(urdf_joint_name)
            
            # 保持数据顺序一致
            if i < len(msg.position):
                joint_state.position.append(msg.position[i])
            else:
                joint_state.position.append(0.0)
                
            if i < len(msg.velocity):
                joint_state.velocity.append(msg.velocity[i])
            else:
                joint_state.velocity.append(0.0)
                
            if i < len(msg.effort):
                joint_state.effort.append(msg.effort[i])
            else:
                joint_state.effort.append(0.0)
        
        self.joint_state_pub.publish(joint_state)


def main(args=None):
    rclpy.init(args=args)
    node = GimbalJointPublisher()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    except Exception as e:
        node.get_logger().error(f'Error in gimbal_joint_publisher: {e}')
    finally:
        try:
            node.destroy_node()
        except:
            pass
        try:
            if rclpy.ok():
                rclpy.shutdown()
        except:
            pass


if __name__ == '__main__':
    main()
