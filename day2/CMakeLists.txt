cmake_minimum_required(VERSION 3.0)

project(DAY2)

set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-Wall -std=c++11)

include_directories(include)

add_library(erroif SHARED src/erroif.cpp)

add_executable(client src/client.cpp)
add_executable(server src/server.cpp)

target_link_libraries(client erroif)
target_link_libraries(server erroif)