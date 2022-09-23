cmake_minimum_required(VERSION 3.5)

project(mfi_keyboard_parser LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


add_executable(mfi_keyboard_parser
    main.cpp
    mfikeypadparser.cpp
    mfikeypadparser.h
    structkeypad.h
    )
target_link_libraries(mfi_keyboard_parser Qt5::Core -lgtest -lpthread)
