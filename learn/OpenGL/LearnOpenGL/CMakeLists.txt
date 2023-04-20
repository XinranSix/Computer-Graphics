cmake_minimum_required(VERSION 3.10)

project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include_directories(./include)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

aux_source_directory(./src/imgui IMGUI_LIST)
aux_source_directory(./test TEST_LIST)
aux_source_directory(./src/1.hello_window SRC_LIST1)
aux_source_directory(./src/2.hello_window_clear SRC_LIST2)
aux_source_directory(./src/3.hello_triangle_indexed SRC_LIST3)
aux_source_directory(./src/3.hello_triangle_exercise1 SRC_LIST4)
aux_source_directory(./src/3.hello_triangle_exercise2 SRC_LIST5)
aux_source_directory(./src/3.hello_triangle_exercise3 SRC_LIST6)
aux_source_directory(./src/4.shaders_uniform SRC_LIST7)
aux_source_directory(./src/5.shaders_interpolation SRC_LIST8)
aux_source_directory(./src/6.shaders_exercise1 SRC_LIST9)
aux_source_directory(./src/6.shaders_exercise2 SRC_LIST10)
aux_source_directory(./src/6.shaders_exercise3 SRC_LIST11)
aux_source_directory(./src/6.shaders_exercise4 SRC_LIST12)
aux_source_directory(./src/7.textures SRC_LIST13)
aux_source_directory(./src/8.textures_exercise1 SRC_LIST14)
aux_source_directory(./src/8.textures_exercise2 SRC_LIST15)
aux_source_directory(./src/8.textures_exercise3 SRC_LIST16)
aux_source_directory(./src/8.textures_exercise4 SRC_LIST17)


MESSAGE(${TEST_LIST})
MESSAGE(${SRC_LIST1})

set(
        EXECUTABLE_LIST
        test
        1.hello_window
        2.hello_window_clear
        3.hello_triangle_indexed
        3.hello_triangle_exercise1
        3.hello_triangle_exercise2
        3.hello_triangle_exercise3
        5.shaders_interpolation
        6.shaders_exercise1
        6.shaders_exercise2
        6.shaders_exercise3
        6.shaders_exercise4
        7.textures
        8.textures_exercise1
        8.textures_exercise2
        8.textures_exercise3
        8.textures_exercise4
        4.shaders_uniform
)

set(
        SOURCE_LIST
        ${TEST_LIST}
        ${SRC_LIST1}
        ${SRC_LIST2}
        ${SRC_LIST3}
        ${SRC_LIST4}
        ${SRC_LIST5}
        ${SRC_LIST6}
        ${SRC_LIST8}
        ${SRC_LIST9}
        ${SRC_LIST10}
        ${SRC_LIST11}
        ${SRC_LIST12}
        ${SRC_LIST13}
        ${SRC_LIST14}
        ${SRC_LIST15}
        ${SRC_LIST16}
        ${SRC_LIST17}
        ${SRC_LIST7}


)

list(LENGTH EXECUTABLE_LIST len)
math(EXPR len "${len} - 1")

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

foreach (i RANGE ${len})
    list(GET EXECUTABLE_LIST ${i} val1)
    list(GET SOURCE_LIST ${i} val2)

    message("${val1} ${val2}")

    add_executable(${val1} ${val2} ${IMGUI_LIST})

    target_link_libraries(${val1} PRIVATE glfw)
    target_link_libraries(${val1} PRIVATE OpenGL::GL)
    target_link_libraries(${val1} PRIVATE glad::glad)
    target_link_libraries(${val1} PRIVATE imgui::imgui)

    add_custom_command(
            TARGET ${val1}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/assets"
            "$<TARGET_FILE_DIR:${val1}>/assets")

    add_custom_command(
            TARGET ${val1}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/shader/"
            "$<TARGET_FILE_DIR:${val1}>/shader")
endforeach ()


