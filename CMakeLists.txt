cmake_minimum_required(VERSION 2.8)

project(subgine)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

file(GLOB_RECURSE SYSTEM_SRC_FILES "${CMAKE_SOURCE_DIR}/System/*.cpp")
file(GLOB_RECURSE PHYSIC_SRC_FILES "${CMAKE_SOURCE_DIR}/Physic/*.cpp")
file(GLOB_RECURSE COLLISION_SRC_FILES "${CMAKE_SOURCE_DIR}/Collision/*.cpp")

include_directories("${CMAKE_SOURCE_DIR}")

add_library(subgine-system SHARED ${SYSTEM_SRC_FILES})
add_library(subgine-physic SHARED ${PHYSIC_SRC_FILES})
add_library(subgine-collision SHARED ${COLLISION_SRC_FILES})

target_link_libraries(subgine-collision subgine-system)
target_link_libraries(subgine-physic subgine-collision subgine-system)

install(TARGETS subgine-system DESTINATION lib)
install(TARGETS subgine-physic DESTINATION lib)
install(TARGETS subgine-collision DESTINATION lib)

install(DIRECTORY src/ DESTINATION include/subgine FILES_MATCHING
	PATTERN "*.hpp"
	PATTERN "*.h"
	PATTERN "build" EXCLUDE
	PATTERN ".*" EXCLUDE
	PATTERN "*~" EXCLUDE
	PATTERN "build/" EXCLUDE
	PATTERN ".svn/" EXCLUDE
	PATTERN ".git/" EXCLUDE
)
