cmake_minimum_required(VERSION 3.26)
project(Computational_Finance)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
include_directories(src)

add_executable(Computational_Finance
        main.cpp)
