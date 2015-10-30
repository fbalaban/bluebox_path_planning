# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "waypoint_planning: 1 messages, 0 services")

set(MSG_I_FLAGS "-Iwaypoint_planning:/home/fotis/Dev/Workspaces/ROS/bluebox_path_planning/src/waypoint_planning/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(waypoint_planning_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/fotis/Dev/Workspaces/ROS/bluebox_path_planning/src/waypoint_planning/msg/Coordinates.msg" NAME_WE)
add_custom_target(_waypoint_planning_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "waypoint_planning" "/home/fotis/Dev/Workspaces/ROS/bluebox_path_planning/src/waypoint_planning/msg/Coordinates.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(waypoint_planning
  "/home/fotis/Dev/Workspaces/ROS/bluebox_path_planning/src/waypoint_planning/msg/Coordinates.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/waypoint_planning
)

### Generating Services

### Generating Module File
_generate_module_cpp(waypoint_planning
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/waypoint_planning
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(waypoint_planning_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(waypoint_planning_generate_messages waypoint_planning_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fotis/Dev/Workspaces/ROS/bluebox_path_planning/src/waypoint_planning/msg/Coordinates.msg" NAME_WE)
add_dependencies(waypoint_planning_generate_messages_cpp _waypoint_planning_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(waypoint_planning_gencpp)
add_dependencies(waypoint_planning_gencpp waypoint_planning_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS waypoint_planning_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(waypoint_planning
  "/home/fotis/Dev/Workspaces/ROS/bluebox_path_planning/src/waypoint_planning/msg/Coordinates.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/waypoint_planning
)

### Generating Services

### Generating Module File
_generate_module_lisp(waypoint_planning
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/waypoint_planning
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(waypoint_planning_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(waypoint_planning_generate_messages waypoint_planning_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fotis/Dev/Workspaces/ROS/bluebox_path_planning/src/waypoint_planning/msg/Coordinates.msg" NAME_WE)
add_dependencies(waypoint_planning_generate_messages_lisp _waypoint_planning_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(waypoint_planning_genlisp)
add_dependencies(waypoint_planning_genlisp waypoint_planning_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS waypoint_planning_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(waypoint_planning
  "/home/fotis/Dev/Workspaces/ROS/bluebox_path_planning/src/waypoint_planning/msg/Coordinates.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/waypoint_planning
)

### Generating Services

### Generating Module File
_generate_module_py(waypoint_planning
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/waypoint_planning
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(waypoint_planning_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(waypoint_planning_generate_messages waypoint_planning_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fotis/Dev/Workspaces/ROS/bluebox_path_planning/src/waypoint_planning/msg/Coordinates.msg" NAME_WE)
add_dependencies(waypoint_planning_generate_messages_py _waypoint_planning_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(waypoint_planning_genpy)
add_dependencies(waypoint_planning_genpy waypoint_planning_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS waypoint_planning_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/waypoint_planning)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/waypoint_planning
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(waypoint_planning_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/waypoint_planning)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/waypoint_planning
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(waypoint_planning_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/waypoint_planning)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/waypoint_planning\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/waypoint_planning
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(waypoint_planning_generate_messages_py std_msgs_generate_messages_py)
