# CMakeList.txt: CMake project of stapler_engine
#
cmake_minimum_required (VERSION 3.12)

# Use hot cmp0141
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("stapler_engine")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_COMPILER_WORKS TRUE)
set(CMAKE_CXX_COMPILER_WORKS TRUE)

add_definitions(-DS_DLL_LIB)
add_definitions(-DSTAPLER_ENGINE_EXPORTS)
add_definitions(-DUNICODE)

file(GLOB_RECURSE S_HEADER_FILE RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.h")

file(GLOB_RECURSE S_SRC_FILE "src/*.cpp")

# 遍历文件并复制
foreach(file ${S_HEADER_FILE})
    # 获取文件的目录部分
    get_filename_component(file_dir ${file} DIRECTORY)
    
    # 创建目标目录
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${file_dir})
    
    # 复制文件
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/${file}
        ${CMAKE_CURRENT_BINARY_DIR}/${file}
        COPYONLY
    )
endforeach()

file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/include)

file(RENAME ${CMAKE_CURRENT_BINARY_DIR}/src ${CMAKE_CURRENT_BINARY_DIR}/include)

add_library(stapler_engine SHARED ${S_SRC_FILE})
