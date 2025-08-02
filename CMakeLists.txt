# CMakeList.txt
# CMake project of stapler_engine
#

cmake_minimum_required(VERSION 3.12)

project(stapler_engine)

# Use hot cmp0141
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_C_COMPILER_WORKS TRUE)
# set(CMAKE_CXX_COMPILER_WORKS TRUE)

include_directories("src")

add_subdirectory("src")

add_subdirectory("test")