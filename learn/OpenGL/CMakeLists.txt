cmake_minimum_required(VERSION 3.10)

project(Learn_OpenGL)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(./src SRC_LIST)
aux_source_directory(./test TEST_LIST)

add_executable(main ${SRC_LIST})
add_executable(test ${TEST_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

include_directories(./include)

target_link_libraries(main PRIVATE glfw)
target_link_libraries(main PRIVATE OpenGL::GL)
target_link_libraries(main PRIVATE glad::glad)

target_link_libraries(test PRIVATE glfw)
target_link_libraries(test PRIVATE OpenGL::GL)
target_link_libraries(test PRIVATE glad::glad)

add_custom_command(
        TARGET main
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/assets"
        "$<TARGET_FILE_DIR:main>/assets")

add_custom_command(
        TARGET main
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/shader"
        "$<TARGET_FILE_DIR:main>/shader")
