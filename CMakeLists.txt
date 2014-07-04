cmake_minimum_required(VERSION 2.8)
PROJECT(GAME)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${GAME_SOURCE_DIR}/cmake")

find_package(OpenGL REQUIRED)
find_package(SDL2   REQUIRED)
find_package(GLEW   REQUIRED)
find_package(GLM    REQUIRED)
find_package(SDL2_mixer   REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIR})
include_directories(${GLM_INCLUDE_DIR})
include_directories(${SDL2_MIXER_INCLUDE_DIR})
include_directories(include)

file(GLOB source "src/*.cpp")
add_executable(game ${source})
target_link_libraries(
          game 
          ${SDL2_LIBRARY}
          ${OPENGL_LIBRARIES}
          ${GLEW_LIBRARY}
          ${SDL2_MIXER_LIBRARY}
          )