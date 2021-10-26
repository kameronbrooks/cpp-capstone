cmake_minimum_required(VERSION 3.11.3)

set(CMAKE_CXX_STANDARD 17)

project(Chess)


file(GLOB project_SRCS src/*.cpp)

add_executable(chess ${project_SRCS})

