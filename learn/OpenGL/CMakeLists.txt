cmake_minimum_required(VERSION 3.10)

project(Example)

add_executable(Example main.cpp)

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(Example PRIVATE glfw)
target_link_libraries(Example PRIVATE OpenGL::GL)
target_link_libraries(Example PRIVATE glad::glad)