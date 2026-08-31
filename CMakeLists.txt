cmake_minimum_required(VERSION 3.21)

project(FreddyBoop VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

# Geode build system
include($ENV{GEODE_SDK}/cmake/Geode.cmake)
setup_geode_mod(${PROJECT_NAME})
