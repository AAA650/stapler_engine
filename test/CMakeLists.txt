# CMakeLists.txt
# Make test se exe

add_definitions(-DUNICODE)

remove_definitions(-DSTAPLER_ENGINE_EXPORTS)

add_executable(test_se main.cpp)

target_link_libraries(test_se stapler_engine)