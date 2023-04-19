aux_source_directory (. SRC_LIST)

add_executable(4.1.textures ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(4.1.textures PRIVATE glfw)
target_link_libraries(4.1.textures PRIVATE OpenGL::GL)
target_link_libraries(4.1.textures PRIVATE glad::glad)

add_custom_command(
        TARGET 4.1.textures
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/assets"
        "$<TARGET_FILE_DIR:4.1.textures>/assets")

add_custom_command(
        TARGET 4.1.textures
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/shader/"
        "$<TARGET_FILE_DIR:4.1.textures>/shader")
