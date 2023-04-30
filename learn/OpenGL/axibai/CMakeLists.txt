cmake_minimum_required(VERSION 3.10)

project(axibai)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include_directories(./include)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

aux_source_directory(./src/sample_1_1HelloWindow SRC_LIST1)
aux_source_directory(./src/sample_1_2HelloTriangle SRC_LIST2)
aux_source_directory(./src/sample_1_2HelloTriangle2 SRC_LIST3)
aux_source_directory(./src/sample_1_2HelloTriangle3 SRC_LIST4)
aux_source_directory(./src/sample_1_2HelloTriangle_exercise1 SRC_LIST5)
aux_source_directory(./src/sample_1_2HelloTriangle_exercise2 SRC_LIST6)
aux_source_directory(./src/sample_1_2HelloTriangle_exercise3 SRC_LIST7)
aux_source_directory(./src/sample_1_3Shaders SRC_LIST8)
aux_source_directory(./src/sample_1_3Shaders2 SRC_LIST9)
aux_source_directory(./src/sample_1_3Shaders3 SRC_LIST10)
aux_source_directory(./src/sample_1_3Shaders3_exercise1 SRC_LIST11)
aux_source_directory(./src/sample_1_3Shaders3_exercise2 SRC_LIST12)
aux_source_directory(./src/sample_1_3Shaders3_exercise3 SRC_LIST13)
aux_source_directory(./src/sample_1_3Shaders3_exercise4 SRC_LIST14)
aux_source_directory(./src/sample_1_3Shaders4 SRC_LIST15)
aux_source_directory(./src/sample_1_4Texture SRC_LIST16)
aux_source_directory(./src/sample_1_4Texture2 SRC_LIST17)
aux_source_directory(./src/sample_1_4Texture3 SRC_LIST18)
aux_source_directory(./src/sample_1_4Texture4 SRC_LIST19)
aux_source_directory(./src/sample_1_4Texture_exercise1 SRC_LIST20)
aux_source_directory(./src/sample_1_4Texture_exercise2 SRC_LIST21)
aux_source_directory(./src/sample_1_4Texture_exercise3 SRC_LIST22)
aux_source_directory(./src/sample_1_4Texture_exercise4 SRC_LIST23)
aux_source_directory(./src/sample_1_5Transformations SRC_LIST24)
aux_source_directory(./src/sample_1_5Transformations_exercise1 SRC_LIST25)
aux_source_directory(./src/sample_1_5Transformations_exercise2 SRC_LIST26)
aux_source_directory(./src/sample_1_6CoordinateSystem SRC_LIST27)
aux_source_directory(./src/sample_1_6CoordinateSystem2 SRC_LIST28)
aux_source_directory(./src/sample_1_6CoordinateSystem_exercise1 SRC_LIST29)
aux_source_directory(./src/sample_1_6CoordinateSystem_exercise2 SRC_LIST30)
aux_source_directory(./src/sample_1_6CoordinateSystem_exercise3 SRC_LIST31)
aux_source_directory(./src/sample_1_7Camera SRC_LIST32)
aux_source_directory(./src/sample_1_7Camera_2 SRC_LIST33)
aux_source_directory(./src/sample_1_7Camera_exercise1 SRC_LIST34)
aux_source_directory(./src/sample_1_7Camera_exercise2 SRC_LIST35)
aux_source_directory(./src/sample_2_1Color SRC_LIST36)
aux_source_directory(./src/sample_2_2Phong SRC_LIST37)
aux_source_directory(./src/sample_2_2Phong_exercise1 SRC_LIST38)
aux_source_directory(./src/sample_2_2Phong_exercise2 SRC_LIST39)
aux_source_directory(./src/sample_2_2Phong_exercise3 SRC_LIST40)
aux_source_directory(./src/sample_2_2Phong_exercise4 SRC_LIST41)
aux_source_directory(./src/sample_2_3Material SRC_LIST42)
aux_source_directory(./src/sample_2_3Material_exericse1 SRC_LIST43)
aux_source_directory(./src/sample_2_3Material_exericse2 SRC_LIST44)
aux_source_directory(./src/sample_2_4LightingMap SRC_LIST45)
aux_source_directory(./src/sample_2_4LightingMap_exercise1 SRC_LIST46)
aux_source_directory(./src/sample_2_4LightingMap_exercise2 SRC_LIST47)
aux_source_directory(./src/sample_2_4LightingMap_exercise3 SRC_LIST48)
aux_source_directory(./src/sample_2_5LightCaster SRC_LIST49)
aux_source_directory(./src/sample_2_5LightCaster_2 SRC_LIST50)
aux_source_directory(./src/sample_2_5LightCaster_3 SRC_LIST51)
aux_source_directory(./src/sample_2_6MultipleLights SRC_LIST52)
aux_source_directory(./src/sample_2_6MultipleLights_exercise1 SRC_LIST53)
aux_source_directory(./src/sample_2_6MultipleLights_exercise2 SRC_LIST54)
aux_source_directory(./src/sample_2_6MultipleLights_exercise3 SRC_LIST55)
aux_source_directory(./src/sample_2_6MultipleLights_exercise4 SRC_LIST56)


set(
        EXECUTABLE_LIST
        sample_1_1HelloWindow
        sample_1_2HelloTriangle
        sample_1_2HelloTriangle2
        sample_1_2HelloTriangle3
        sample_1_2HelloTriangle_exercise1
        sample_1_2HelloTriangle_exercise2
        sample_1_2HelloTriangle_exercise3
        sample_1_3Shaders
        sample_1_3Shaders2
        sample_1_3Shaders3
        sample_1_3Shaders3_exercise1
        sample_1_3Shaders3_exercise2
        sample_1_3Shaders3_exercise3
        sample_1_3Shaders3_exercise4
        sample_1_3Shaders4
        sample_1_4Texture
        sample_1_4Texture2
        sample_1_4Texture3
        sample_1_4Texture4
        sample_1_4Texture_exercise1
        sample_1_4Texture_exercise2
        sample_1_4Texture_exercise3
        sample_1_4Texture_exercise4
        sample_1_5Transformations
        sample_1_5Transformations_exercise1
        sample_1_5Transformations_exercise2
        sample_1_6CoordinateSystem
        sample_1_6CoordinateSystem2
        sample_1_6CoordinateSystem_exercise1
        sample_1_6CoordinateSystem_exercise2
        sample_1_6CoordinateSystem_exercise3
        sample_1_7Camera
        sample_1_7Camera_2
        sample_1_7Camera_exercise1
        sample_1_7Camera_exercise2
        sample_2_1Color
        sample_2_2Phong
        sample_2_2Phong_exercise1
        sample_2_2Phong_exercise2
        sample_2_2Phong_exercise3
        sample_2_2Phong_exercise4
        sample_2_3Material
        sample_2_3Material_exericse1
        sample_2_3Material_exericse2
        sample_2_4LightingMap
        sample_2_4LightingMap_exercise1
        sample_2_4LightingMap_exercise2
        sample_2_4LightingMap_exercise3
        sample_2_5LightCaster
        sample_2_5LightCaster_2
        sample_2_5LightCaster_3
        sample_2_6MultipleLights
        sample_2_6MultipleLights_exercise1
        sample_2_6MultipleLights_exercise2
        sample_2_6MultipleLights_exercise3
        sample_2_6MultipleLights_exercise4
)

set(
        SOURCE_LIST
        ${SRC_LIST1}
        ${SRC_LIST2}
        ${SRC_LIST3}
        ${SRC_LIST4}
        ${SRC_LIST5}
        ${SRC_LIST6}
        ${SRC_LIST7}
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
        ${SRC_LIST18}
        ${SRC_LIST19}
        ${SRC_LIST20}
        ${SRC_LIST21}
        ${SRC_LIST22}
        ${SRC_LIST23}
        ${SRC_LIST24}
        ${SRC_LIST25}
        ${SRC_LIST26}
        ${SRC_LIST27}
        ${SRC_LIST28}
        ${SRC_LIST29}
        ${SRC_LIST30}
        ${SRC_LIST31}
        ${SRC_LIST32}
        ${SRC_LIST33}
        ${SRC_LIST34}
        ${SRC_LIST35}
        ${SRC_LIST36}
        ${SRC_LIST37}
        ${SRC_LIST38}
        ${SRC_LIST39}
        ${SRC_LIST40}
        ${SRC_LIST41}
        ${SRC_LIST42}
        ${SRC_LIST43}
        ${SRC_LIST44}
        ${SRC_LIST45}
        ${SRC_LIST46}
        ${SRC_LIST47}
        ${SRC_LIST48}
        ${SRC_LIST49}
        ${SRC_LIST50}
        ${SRC_LIST51}
        ${SRC_LIST52}
        ${SRC_LIST53}
        ${SRC_LIST54}
        ${SRC_LIST55}
        ${SRC_LIST56}
)

aux_source_directory(./lib/ OTHER_LIST)

list(LENGTH EXECUTABLE_LIST len)
math(EXPR len "${len} - 1")

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)

foreach (i RANGE ${len})
    list(GET EXECUTABLE_LIST ${i} val1)
    list(GET SOURCE_LIST ${i} val2)

    add_executable(${val1} ${val2} ${OTHER_LIST})

    target_link_libraries(${val1} PRIVATE glfw)
    target_link_libraries(${val1} PRIVATE OpenGL::GL)
    target_link_libraries(${val1} PRIVATE glad::glad)
    target_link_libraries(${val1} PRIVATE imgui::imgui)
    target_link_libraries(${val1} PRIVATE glm::glm)
    target_link_libraries(${val1} PRIVATE fmt::fmt)
    target_link_libraries(${val1} PRIVATE assimp::assimp)

    add_custom_command(
            TARGET ${val1}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/assets"
            "$<TARGET_FILE_DIR:${val1}>/assets")

    add_custom_command(
            TARGET ${val1}
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/src/${val1}/shaders/"
            "$<TARGET_FILE_DIR:${val1}>/shaders")

endforeach ()
