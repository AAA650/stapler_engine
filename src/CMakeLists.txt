# CMakeLists.txt
# Make stapler_engine dll

add_definitions(-DS_DLL_LIB)
add_definitions(-DSTAPLER_ENGINE_EXPORTS)
add_definitions(-DUNICODE)

file(GLOB_RECURSE S_HEADER_FILE RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.h")

file(GLOB_RECURSE S_SRC_FILE "*.cpp")

# Copy all headers
foreach(file ${S_HEADER_FILE})
	# copy file
	configure_file(
		${CMAKE_CURRENT_SOURCE_DIR}/${file}
		${PROJECT_BINARY_DIR}/include/${file}
		COPYONLY
	)

endforeach()

add_library(stapler_engine SHARED ${S_SRC_FILE})

install(TARGETS stapler_engine
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
