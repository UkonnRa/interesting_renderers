cmake_minimum_required(VERSION 3.17)
project(common)

set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)

file(GLOB_RECURSE DIR_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)
add_library(common ${DIR_SRC})

target_include_directories(common PUBLIC ./include)

find_package(Threads REQUIRED)

find_package(glad CONFIG REQUIRED)
target_link_libraries(common PUBLIC glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(common PUBLIC glfw)

find_package(assimp CONFIG REQUIRED)
target_link_libraries(common PUBLIC assimp::assimp)

find_package(glm CONFIG REQUIRED)
target_link_libraries(common PUBLIC glm)
