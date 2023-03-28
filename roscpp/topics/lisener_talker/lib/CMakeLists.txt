project(msg)
add_library(msg src/msg.cpp)
target_include_directories(msg  PUBLIC  ${PROJECT_SOURCE_DIR}/include)
