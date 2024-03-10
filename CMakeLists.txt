cmake_minimum_required(VERSION 3.27)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        task.cpp
        task.h
        solution.cpp
        solution.h
        problem.cpp
        problem.h)
