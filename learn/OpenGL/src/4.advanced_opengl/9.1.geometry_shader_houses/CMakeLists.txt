aux_source_directory (. SRC_LIST)

add_executable(9.1.geometry_shader_houses ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(9.1.geometry_shader_houses PRIVATE glfw)
target_link_libraries(9.1.geometry_shader_houses PRIVATE OpenGL::GL)
target_link_libraries(9.1.geometry_shader_houses PRIVATE glad::glad)
