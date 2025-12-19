from rclpy.node import Node
from rclpy import logging
from std_msgs.msg import UInt8
from rclpy.qos import QoSProfile

class CallBackMsg(Node):
    def __init__(self):
        self.current_robot_hp = 600

    def callback_refree(self, msg):
        self.current_robot_hp = msg.robot_hp


    