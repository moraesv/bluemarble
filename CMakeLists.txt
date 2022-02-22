cmake_minimum_required(VERSION 3.12)

project(BlueMarble)

add_executable(BlueMarble main.cpp)

target_include_directories(BlueMarble PRIVATE deps/glm)