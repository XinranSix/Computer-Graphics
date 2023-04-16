cmake_minimum_required(VERSION 3.10)

project(Example)

include_directories(
    ${PROJECT_SOURCE_DIR}/include/
)

add_subdirectory( ${PROJECT_SOURCE_DIR}/include/ )

add_executable(Example main.cpp)
