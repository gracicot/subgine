cmake_minimum_required(VERSION 2.8)
project(subgine)
include_directories("${PROJECT_BINARY_DIR}")
ADD_DEFINITIONS("-std=c++0x")

file(GLOB_RECURSE SYSTEM_SRC_FILES "${CMAKE_SOURCE_DIR}/System/*.cpp")
file(GLOB_RECURSE PHYSIC_SRC_FILES "${CMAKE_SOURCE_DIR}/Physic/*.cpp")
file(GLOB_RECURSE COLLISION_SRC_FILES "${CMAKE_SOURCE_DIR}/Collision/*.cpp")
file(GLOB_RECURSE PARTICLE_SRC_FILES "${CMAKE_SOURCE_DIR}/Particle/*.cpp")

add_library(subgine-system SHARED ${SYSTEM_SRC_FILES})
add_library(subgine-physic SHARED ${PHYSIC_SRC_FILES})
add_library(subgine-collision SHARED ${COLLISION_SRC_FILES})
add_library(subgine-particle SHARED ${PARTICLE_SRC_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 1.6 REQUIRED system)

target_link_libraries(subgine-system ${SFML_LIBRARIES})

install(TARGETS subgine-system DESTINATION lib)
install(TARGETS subgine-physic DESTINATION lib)
install(TARGETS subgine-collision DESTINATION lib)
install(TARGETS subgine-particle DESTINATION lib)