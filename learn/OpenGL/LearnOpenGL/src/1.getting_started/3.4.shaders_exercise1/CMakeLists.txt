aux_source_directory(. SRC_LIST)

add_executable(3.4.shaders_exercise1 ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(3.4.shaders_exercise1 PRIVATE glfw)
target_link_libraries(3.4.shaders_exercise1 PRIVATE OpenGL::GL)
target_link_libraries(3.4.shaders_exercise1 PRIVATE glad::glad)

add_custom_command(
        TARGET 3.4.shaders_exercise1
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/assets"
        "$<TARGET_FILE_DIR:3.3.shaders_class>/assets")

add_custom_command(
        TARGET 3.4.shaders_exercise1
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/shader/"
        "$<TARGET_FILE_DIR:3.3.shaders_class>/shader")

