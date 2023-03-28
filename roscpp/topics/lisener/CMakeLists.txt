cmake_minimum_required(VERSION 3.0.2)
project(lisner)


find_package(catkin REQUIRED COMPONENTS  roscpp  std_msgs )

catkin_package()



 add_executable(${PROJECT_NAME}_node src/lisner_node.cpp)

 target_link_libraries(${PROJECT_NAME}_node
   ${catkin_LIBRARIES}
 )

