cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
# stapler_engine CMakeLists.txt
# CMake list of stapler_engine
# Copyright (c) 2026 AAA650
#
project(stapler_engine)

include_directories(./)
add_subdirectory(base)
add_subdirectory(core)
add_subdirectory(main)

