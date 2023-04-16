cmake_minimum_required(VERSION 3.10)

project(OpenGlWithTheCherno)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include_directories(./include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory (./src SRC_LIST)
aux_source_directory (./test TEST_LIST)

add_executable(main ${SRC_LIST})
add_executable(test ${TEST_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(main PRIVATE glfw)
target_link_libraries(main PRIVATE OpenGL::GL)
target_link_libraries(main PRIVATE glad::glad)

target_link_libraries(test PRIVATE glfw)
target_link_libraries(test PRIVATE OpenGL::GL)
target_link_libraries(test PRIVATE glad::glad)
