aux_source_directory (. SRC_LIST)

add_executable(1.2.lighting_textured ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(1.2.lighting_textured PRIVATE glfw)
target_link_libraries(1.2.lighting_textured PRIVATE OpenGL::GL)
target_link_libraries(1.2.lighting_textured PRIVATE glad::glad)
