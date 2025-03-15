# CMakeList.txt: CMake project of stapler_engine
#
cmake_minimum_required (VERSION 3.8)

# Use hot cmp0141
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("stapler_engine")

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DSTAPLER_ENGINE_EXPORTS)

include_directories("include")

file(GLOB_RECURSE SE_SRC_FILE "src/*.cpp")

add_library(stapler_engine SHARED ${SE_SRC_FILE})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET stapler_engine PROPERTY CXX_STANDARD 20)
endif()

