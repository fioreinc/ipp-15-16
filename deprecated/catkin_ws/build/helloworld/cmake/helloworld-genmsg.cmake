# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "helloworld: 1 messages, 1 services")

set(MSG_I_FLAGS "-Ihelloworld:/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(helloworld_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/srv/GetFactor.srv" NAME_WE)
add_custom_target(_helloworld_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "helloworld" "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/srv/GetFactor.srv" ""
)

get_filename_component(_filename "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/msg/TestMsg.msg" NAME_WE)
add_custom_target(_helloworld_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "helloworld" "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/msg/TestMsg.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(helloworld
  "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/msg/TestMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/helloworld
)

### Generating Services
_generate_srv_cpp(helloworld
  "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/srv/GetFactor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/helloworld
)

### Generating Module File
_generate_module_cpp(helloworld
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/helloworld
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(helloworld_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(helloworld_generate_messages helloworld_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/srv/GetFactor.srv" NAME_WE)
add_dependencies(helloworld_generate_messages_cpp _helloworld_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/msg/TestMsg.msg" NAME_WE)
add_dependencies(helloworld_generate_messages_cpp _helloworld_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(helloworld_gencpp)
add_dependencies(helloworld_gencpp helloworld_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS helloworld_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(helloworld
  "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/msg/TestMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/helloworld
)

### Generating Services
_generate_srv_lisp(helloworld
  "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/srv/GetFactor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/helloworld
)

### Generating Module File
_generate_module_lisp(helloworld
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/helloworld
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(helloworld_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(helloworld_generate_messages helloworld_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/srv/GetFactor.srv" NAME_WE)
add_dependencies(helloworld_generate_messages_lisp _helloworld_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/msg/TestMsg.msg" NAME_WE)
add_dependencies(helloworld_generate_messages_lisp _helloworld_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(helloworld_genlisp)
add_dependencies(helloworld_genlisp helloworld_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS helloworld_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(helloworld
  "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/msg/TestMsg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/helloworld
)

### Generating Services
_generate_srv_py(helloworld
  "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/srv/GetFactor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/helloworld
)

### Generating Module File
_generate_module_py(helloworld
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/helloworld
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(helloworld_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(helloworld_generate_messages helloworld_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/srv/GetFactor.srv" NAME_WE)
add_dependencies(helloworld_generate_messages_py _helloworld_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ethietter/fiore-ipp/ipp-15-16/catkin_ws/src/helloworld/msg/TestMsg.msg" NAME_WE)
add_dependencies(helloworld_generate_messages_py _helloworld_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(helloworld_genpy)
add_dependencies(helloworld_genpy helloworld_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS helloworld_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/helloworld)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/helloworld
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(helloworld_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/helloworld)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/helloworld
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(helloworld_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/helloworld)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/helloworld\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/helloworld
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(helloworld_generate_messages_py std_msgs_generate_messages_py)
