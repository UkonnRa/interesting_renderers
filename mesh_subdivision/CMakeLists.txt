cmake_minimum_required(VERSION 3.17)
project(mesh_subdivision LANGUAGES CXX CUDA)

set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)

include_directories(../common/include ./include)

file(GLOB_RECURSE DIR_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp include/*.h test/*.cpp)
add_executable(mesh_subdivision ${DIR_SRC})

target_link_libraries(mesh_subdivision PUBLIC common)
