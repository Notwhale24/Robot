cmake_minimum_required(VERSION 3.10)
project(robot_controller)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Исходные файлы
set(SOURCES
    main.cpp
    FooEngine.h
    FooCmdReceiver.h
    AEngine.h
    ACmdReceiver.h
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(robot_controller ${SOURCES})