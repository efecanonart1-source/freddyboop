cmake_minimum_required(VERSION 3.21)

project(FreddyBoop)

add_library(FreddyBoop SHARED
    src/main.cpp
)

target_include_directories(FreddyBoop PRIVATE
    include
)
