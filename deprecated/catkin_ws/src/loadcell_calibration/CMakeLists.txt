cmake_minimum_required(VERSION 2.8.3)
project(loadcell_calibration)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  message_generation
  rosserial_arduino
  rosserial_client
)

add_service_files(
    FILES
    GetFactor.srv
)

generate_messages(
    DEPENDENCIES
    std_msgs
)

catkin_package()

rosserial_generate_ros_lib(
    PACKAGE rosserial_arduino
    SCRIPT make_libraries.py
)

rosserial_configure_client(
    DIRECTORY arduino
    TOOLCHAIN_FILE ${ROSSERIAL_ARDUINO_TOOLCHAIN}
)

rosserial_add_client_target(arduino loadcell_calibration ALL)
rosserial_add_client_target(arduino loadcell_calibration-upload)


include_directories(
  ${catkin_INCLUDE_DIRS}
)
