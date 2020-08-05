cmake_minimum_required(VERSION 3.17)
project(rope_simulation LANGUAGES CXX CUDA)

include_directories(../common/include ./include)

file(GLOB_RECURSE DIR_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)
add_executable(rope_simulation ${DIR_SRC})

target_link_libraries(rope_simulation PUBLIC common)
