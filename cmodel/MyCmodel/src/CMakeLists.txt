
cmake_minimum_required(VERSION 3.10)
add_definitions(-std=c++11)

# -----------------------------------------------------------------
project(model)

include_directories(include)
file(GLOB_RECURSE REMOVE_CMAKE "build/*")
file(GLOB_RECURSE SRC_LIST "*.cpp")
add_executable(model ${SRC_LIST})


target_link_libraries(model ${CMAKE_HOME_DIRECTORY}/libs/libyaml-cpp.so)