aux_source_directory (. SRC_LIST)

add_executable(3.3.shaders_class ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(3.3.shaders_class PRIVATE glfw)
target_link_libraries(3.3.shaders_class PRIVATE OpenGL::GL)
target_link_libraries(3.3.shaders_class PRIVATE glad::glad)

add_custom_command(
        TARGET 3.3.shaders_class
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/assets"
        "$<TARGET_FILE_DIR:3.3.shaders_class>/assets")

add_custom_command(
        TARGET 3.3.shaders_class
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/shader/"
        "$<TARGET_FILE_DIR:3.3.shaders_class>/shader")
