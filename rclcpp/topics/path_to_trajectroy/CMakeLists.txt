cmake_minimum_required(VERSION 3.5)
project(path_to_trajectory)

# Default to C++14

  set(CMAKE_CXX_STANDARD 14)
  add_compile_options(-Wall -Wextra -Wpedantic)


# Find the ROS2 package and the catkin build system
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
#add custom msg
find_package(common_interface REQUIRED) 


#add implementation lib
add_library(trajectory_generator  src/trajectory_generator.cpp)
ament_target_dependencies(trajectory_generator  common_interface nav_msgs )
#make node executable
add_executable(trajectory_node src/trajectory_node.cpp)
ament_target_dependencies(trajectory_node rclcpp  common_interface nav_msgs)

target_link_libraries(trajectory_node trajectory_generator)

target_include_directories(trajectory_node PRIVATE include)

install(TARGETS trajectory_node
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
