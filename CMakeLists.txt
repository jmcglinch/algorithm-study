cmake_minimum_required(VERSION 3.12)
project(algorithm_study C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(algorithm_study
        src/library.c
        src/library.h)
