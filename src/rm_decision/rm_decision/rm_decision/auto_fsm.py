import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from rclpy.qos import QoSProfile
import os
import inspect
import threading
import random
import time
from rm_decision_interfaces.msg import Refree
from geometry_msgs.msg import PoseStamped

from rm_decision.callback_msg import CallBackMsg
from rm_decision.robot_navigator import BasicNavigator
from rm_decision.nav_to_pose import nav_to_pose
from std_msgs.msg import UInt8
from ament_index_python.packages import get_package_share_directory


class AutoFSM(Node):
    def __init__(self):
        super().__init__('auto_fsm_node')

        # 固定参数
        self.set_unhealth_robot_hp = 400

        # set Config: use installed share directory for robust path resolution
        share_dir = get_package_share_directory('rm_decision')
        self.yaml_path = os.path.join(share_dir, 'config', 'goal.yaml')
        self.goal_dict = dict()
        self.goal_path = []
        self.nav_goal_name = []
        self.nav_timeout = 10.0
        self.msg_callback = CallBackMsg()
        self.FSM_state = 0
        self.flag = True

        #Init
        nav_to_pose.yaml_read(self)
        self.init_wait_for_messages()

        # Set rate
        self.rate = self.create_rate(0.5)
        self.rate_nav = self.create_rate(100)

        #接收话题
        self.refree_sub = self.create_subscription(Refree, "/refree_data", self.msg_callback.callback_refree, QoSProfile(depth=1))

        # Connect to Navigation
        self.navigator = BasicNavigator()
        self.navigator.get_logger().info('等待 navigator 服务器连接...')
        self.navigator.waitUntilNav2Active()
        self.navigator.get_logger().info('成功连接导航服务')

        time.sleep(3) # 停滞三秒，让所有 msg 都被正常接收

        #启动多个线程
        self.thread_FSM_state_ = threading.Thread(target=self.thread_FSM_state)
        self.thread_FSM_state_.start()
        self.thread_FSM_ = threading.Thread(target=self.thread_FSM)
        self.thread_FSM_.start()



    def init_wait_for_messages(self):
        message_topics = [
            (Refree, "/refree_data"),
        ]
        for message_type, topic in message_topics:
            self.get_logger().info(f'等待 {topic} 消息')
            nav_to_pose.wait_for_message(self, message_type, topic)

    def thread_FSM_state(self):
        while rclpy.ok():
            self.state_update()
            self.rate_nav.sleep()

    def state_update(self):
        # 仅根据机器人血量与标志位切换：
        # - 血量高且允许进攻(flag=True) -> 进攻
        # - 血量低或未允许进攻 -> 回血
        if self.msg_callback.current_robot_hp > self.set_unhealth_robot_hp and self.flag:
            self.FSM_state = 1  # 进攻
        elif self.msg_callback.current_robot_hp <= self.set_unhealth_robot_hp:
            self.FSM_state = 2  # 回血
        else:
            # 默认保持进攻（例如 flag True 但血量边界情况）
            self.FSM_state = 1

    def thread_FSM(self):
        self.get_logger().info('准备完成, 等待比赛开始')
        while rclpy.ok():
            if self.FSM_state == 1:
                self.mission_attack()
            elif self.FSM_state == 2:
                self.mission_restore()
            elif self.FSM_state == 3:
                self.mission_resist()

    def mission_attack(self):
        self.get_logger().info("开始进攻")
        while self.FSM_state == 1 and rclpy.ok():
            self.get_logger().info("正在进攻状态中...")
            goal_pose = PoseStamped()
            goal_pose.header.frame_id = 'map'
            goal_pose.header.stamp = self.get_clock().now().to_msg()
            goal_pose.pose.position.x = self.goal_dict[self.goal_path[2]][0]
            goal_pose.pose.position.y = self.goal_dict[self.goal_path[2]][1]
            goal_pose.pose.orientation.w = 0.0

            self.navigator.goToPose(goal_pose)
            self.rate.sleep()
        self.get_logger().info("退出进攻")

    
    def mission_restore(self):
        self.get_logger().info("开始回血")
        self.flag = False
        while self.FSM_state == 2 and rclpy.ok():
            self.get_logger().info("正在回血状态中...")
            goal_pose = PoseStamped()
            goal_pose.header.frame_id = 'map'
            goal_pose.header.stamp = self.get_clock().now().to_msg()
            goal_pose.pose.position.x = self.goal_dict[self.goal_path[1]][0]
            goal_pose.pose.position.y = self.goal_dict[self.goal_path[1]][1]
            goal_pose.pose.orientation.w = 0.0

            self.navigator.goToPose(goal_pose)
            if(self.msg_callback.current_robot_hp>=self.set_unhealth_robot_hp+100):
                self.flag = True
            self.rate.sleep()
        self.get_logger().info("退出回血")
            

    def mission_resist(self):
        self.get_logger().info("开始回防")
        while self.FSM_state == 3 and rclpy.ok():
            self.get_logger().info("正在回防状态中...")
            goal_pose = PoseStamped()
            goal_pose.header.frame_id = 'map'
            goal_pose.header.stamp = self.get_clock().now().to_msg()
            goal_pose.pose.position.x = self.goal_dict[self.goal_path[0]][0]
            goal_pose.pose.position.y = self.goal_dict[self.goal_path[0]][1]
            goal_pose.pose.orientation.w = 0.0

            self.navigator.goToPose(goal_pose)
            self.rate.sleep()
        self.get_logger().info("退出回防")

def main():
    rclpy.init()
    auto_fsm = AutoFSM()
    executor = MultiThreadedExecutor()
    executor.add_node(auto_fsm)

    try:
        executor.spin()
    finally:
        executor.shutdown()
        auto_fsm.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
    
        
        

        
    