cmake_minimum_required(VERSION 2.8.3)
project(loadcell_calibration)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  message_generation
)

add_service_files(
    FILES
    GetFactor.srv
)

generate_messages(
    DEPENDENCIES
    std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
