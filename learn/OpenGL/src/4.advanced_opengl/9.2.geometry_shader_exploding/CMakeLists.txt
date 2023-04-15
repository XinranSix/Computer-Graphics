aux_source_directory (. SRC_LIST)

add_executable(9.2.geometry_shader_exploding ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(9.2.geometry_shader_exploding PRIVATE glfw)
target_link_libraries(9.2.geometry_shader_exploding PRIVATE OpenGL::GL)
target_link_libraries(9.2.geometry_shader_exploding PRIVATE glad::glad)
