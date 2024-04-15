cmake_minimum_required(VERSION 3.0)

project(DAY1)

set(CMAKE_BUILD_TYPE Debug)

add_executable(client client.cpp)
add_executable(server server.cpp)
