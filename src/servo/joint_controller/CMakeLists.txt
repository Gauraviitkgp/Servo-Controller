cmake_minimum_required(VERSION 2.8.3)
project(joint_controller)
add_compile_options(-std=c++11)

find_package(catkin REQUIRED
 catkin REQUIRED COMPONENTS
    roscpp
    rospy
    std_msgs
    geometry_msgs
    sensor_msgs
    message_generation
  )



catkin_package()

include_directories(${catkin_INCLUDE_DIRS})

install(DIRECTORY src
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})


add_executable(strt_script src/joint_state_publisher.cpp)

target_link_libraries(strt_script ${catkin_LIBRARIES})
