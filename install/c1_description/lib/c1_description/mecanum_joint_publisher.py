#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import JointState
import math


class MecanumJointPublisher(Node):
    def __init__(self):
        super().__init__('mecanum_joint_publisher')

        # Robot parameters (matching URDF)
        self.R = 0.049       # wheel radius (m)
        self.Lx = 0.11       # half wheelbase (m)
        self.Ly = 0.15       # half track width (m)

        self.joint_names = [
            'front_left_wheel_joint',
            'front_right_wheel_joint',
            'rear_left_wheel_joint',
            'rear_right_wheel_joint',
        ]

        self.wheel_angles = [0.0, 0.0, 0.0, 0.0]
        self.wheel_velocities = [0.0, 0.0, 0.0, 0.0]

        self.sub = self.create_subscription(Twist, 'cmd_vel', self.cmd_vel_cb, 10)
        self.pub = self.create_publisher(JointState, 'joint_states', 10)

        self.rate = 50.0
        self.dt = 1.0 / self.rate
        self.timer = self.create_timer(self.dt, self.publish_joints)

        self.get_logger().info('Mecanum joint publisher started')

    def cmd_vel_cb(self, msg):
        vx = msg.linear.x
        vy = msg.linear.y
        wz = msg.angular.z
        k = self.Lx + self.Ly

        # Mecanum inverse kinematics -> wheel angular velocities
        self.wheel_velocities[0] = (vx - vy - k * wz) / self.R  # FL
        self.wheel_velocities[1] = (vx + vy + k * wz) / self.R  # FR
        self.wheel_velocities[2] = (vx + vy - k * wz) / self.R  # RL
        self.wheel_velocities[3] = (vx - vy + k * wz) / self.R  # RR

    def publish_joints(self):
        for i in range(4):
            self.wheel_angles[i] += self.wheel_velocities[i] * self.dt
            self.wheel_angles[i] = math.fmod(self.wheel_angles[i], 2 * math.pi)

        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.name = self.joint_names
        msg.position = list(self.wheel_angles)
        msg.velocity = list(self.wheel_velocities)
        self.pub.publish(msg)


def main():
    rclpy.init()
    node = MecanumJointPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
