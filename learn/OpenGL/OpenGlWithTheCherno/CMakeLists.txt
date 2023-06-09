cmake_minimum_required(VERSION 3.10)

project(OpenGlWithTheCherno)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(-DCMAKE_EXPORT_COMPILE_COMMANDS 1)

include_directories(./include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(./src SRC_LIST)
aux_source_directory(./test TEST_LIST)

set(EXECUTABLE_LIST)
list(APPEND EXECUTABLE_LIST main)
list(APPEND EXECUTABLE_LIST test)

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(main ${SRC_LIST})
add_executable(test ${TEST_LIST})

foreach (var ${EXECUTABLE_LIST})
    target_link_libraries(${var} PRIVATE glfw)
    target_link_libraries(${var} PRIVATE OpenGL::GL)
    target_link_libraries(${var} PRIVATE GLEW::GLEW)
    target_link_libraries(${var} PRIVATE glm::glm)
    target_link_libraries(${var} PRIVATE fmt::fmt)

    add_custom_command(
            TARGET ${var}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/assets"
            "$<TARGET_FILE_DIR:${var}>/assets")

    add_custom_command(
            TARGET ${var}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/shader/"
            "$<TARGET_FILE_DIR:${var}>/shader")
endforeach ()
