cmake_minimum_required(VERSION 2.8.0)
project(talker_lisner)

find_package(catkin REQUIRED COMPONENTS)
find_package(roscpp REQUIRED)
find_package(std_msgs REQUIRED)

catkin_package()

add_subdirectory(lib)
add_executable(${PROJECT_NAME}_node src/talker_lisner.cpp)
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES} ${roscpp_LIBRARIES} ${std_msgs_LIBRARIES} msg)
