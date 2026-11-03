cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

set(se_core_src core.cpp)

add_library(stapler_engine_core ${se_core_src})
