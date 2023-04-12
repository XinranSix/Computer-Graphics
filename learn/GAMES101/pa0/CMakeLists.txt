cmake_minimum_required(VERSION 3.17)
project(Transformation)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)

add_executable(Transformation main.cpp)

target_compile_features(Transformation PRIVATE cxx_std_17)
set_target_properties(Transformation PROPERTIES CXX_EXTENSIONS OFF)

find_package(Eigen3 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

target_link_libraries(Transformation PRIVATE Eigen3::Eigen)
target_link_libraries(Transformation PRIVATE fmt::fmt)
