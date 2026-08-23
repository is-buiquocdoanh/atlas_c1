#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Node đọc /joy và xuất lệnh đi ngang (strafe) khi giữ nút trái/phải,
# tách riêng khỏi teleop_twist_joy vì node đó chỉ đọc axes[], không đọc buttons[].

import time

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist


class LateralTeleopNode(Node):
    def __init__(self):
        super().__init__('lateral_teleop_node')

        self.declare_parameters(
            namespace='',
            parameters=[
                ('left_button', 3),
                ('right_button', 1),
                ('enable_button', 7),
                ('enable_turbo_button', 6),
                ('require_enable_button', True),
                ('scale_lateral', 0.2),
                ('scale_lateral_turbo', 0.4),
                # Nút vật lý có thể dội tín hiệu (bounce): đọc buttons[] đôi lúc
                # nhảy về 0 dù đang giữ. Giữ trạng thái "đang di chuyển" trong
                # khoảng hold_time kể từ lần đọc true gần nhất để lọc nhiễu này.
                ('hold_time', 0.15),
            ]
        )

        self.left_button = self.get_parameter('left_button').value
        self.right_button = self.get_parameter('right_button').value
        self.enable_button = self.get_parameter('enable_button').value
        self.enable_turbo_button = self.get_parameter('enable_turbo_button').value
        self.require_enable_button = self.get_parameter('require_enable_button').value
        self.scale_lateral = self.get_parameter('scale_lateral').value
        self.scale_lateral_turbo = self.get_parameter('scale_lateral_turbo').value
        self.hold_time = self.get_parameter('hold_time').value

        self.is_moving = False
        self.active_until = 0.0
        self.latched_left = False

        self.sub_joy = self.create_subscription(Joy, 'joy', self.joy_callback, 10)
        self.pub_cmd_vel = self.create_publisher(Twist, 'cmd_vel_lateral', 10)

    def joy_callback(self, joy_msg):
        now = time.monotonic()
        enabled = (not self.require_enable_button) or bool(joy_msg.buttons[self.enable_button])

        left = enabled and bool(joy_msg.buttons[self.left_button])
        right = enabled and bool(joy_msg.buttons[self.right_button])

        if left or right:
            self.active_until = now + self.hold_time
            self.latched_left = left

        if now >= self.active_until:
            if self.is_moving:
                self.pub_cmd_vel.publish(Twist())
                self.is_moving = False
            return

        turbo = bool(joy_msg.buttons[self.enable_turbo_button])
        speed = self.scale_lateral_turbo if turbo else self.scale_lateral

        twist = Twist()
        twist.linear.y = speed if self.latched_left else -speed
        self.pub_cmd_vel.publish(twist)
        self.is_moving = True


def main():
    rclpy.init()
    node = LateralTeleopNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
