cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

set(se_main_src session.cpp main.cpp)

add_executable(stapler_engine_main ${se_main_src})
