cmake_minimum_required(VERSION 2.8.12)

project(dart_unreal)


find_package(DART 6.3 REQUIRED
	COMPONENTS utils gui utils-urdf CONFIG)


add_compile_options(-std=c++11)

include_directories(${DART_INCLUDE_DIRS})


add_executable(dart_unreal main.cpp)
target_link_libraries (dart_unreal ${DART_LIBRARIES})
