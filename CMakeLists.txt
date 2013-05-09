cmake_minimum_required(VERSION 2.8)

project(subgine)
add_definitions("-std=c++0x")

file(GLOB_RECURSE SYSTEM_SRC_FILES "${CMAKE_SOURCE_DIR}/src/System/*.cpp")
file(GLOB_RECURSE PHYSIC_SRC_FILES "${CMAKE_SOURCE_DIR}/src/Physic/*.cpp")
file(GLOB_RECURSE COLLISION_SRC_FILES "${CMAKE_SOURCE_DIR}/src/Collision/*.cpp")
file(GLOB_RECURSE PARTICLE_SRC_FILES "${CMAKE_SOURCE_DIR}/src/Particle/*.cpp")

add_library(subgine-system SHARED ${SYSTEM_SRC_FILES})
add_library(subgine-physic SHARED ${PHYSIC_SRC_FILES})
add_library(subgine-collision SHARED ${COLLISION_SRC_FILES})
add_library(subgine-particle SHARED ${PARTICLE_SRC_FILES})

target_link_libraries(subgine-collision subgine-system)
target_link_libraries(subgine-particle subgine-collision subgine-system subgine-physic)
target_link_libraries(subgine-physic subgine-collision subgine-system)

install(TARGETS subgine-system DESTINATION lib)
install(TARGETS subgine-physic DESTINATION lib)
install(TARGETS subgine-collision DESTINATION lib)
install(TARGETS subgine-particle DESTINATION lib)

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
