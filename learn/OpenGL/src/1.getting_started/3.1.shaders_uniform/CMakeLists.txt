aux_source_directory (. SRC_LIST)

add_executable(3.1.shaders_uniform ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(3.1.shaders_uniform PRIVATE glfw)
target_link_libraries(3.1.shaders_uniform PRIVATE OpenGL::GL)
target_link_libraries(3.1.shaders_uniform PRIVATE glad::glad)
