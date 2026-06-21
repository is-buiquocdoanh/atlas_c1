cmake_minimum_required(VERSION 3.10)
project(c1_description)

find_package(ament_cmake REQUIRED)

install(DIRECTORY urdf launch rviz
  DESTINATION share/${PROJECT_NAME}/
)

install(PROGRAMS
  scripts/mecanum_joint_publisher.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
