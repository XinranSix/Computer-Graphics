aux_source_directory (. SRC_LIST)

add_executable(2.2.2.ibl_specular_textured ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(2.2.2.ibl_specular_textured PRIVATE glfw)
target_link_libraries(2.2.2.ibl_specular_textured PRIVATE OpenGL::GL)
target_link_libraries(2.2.2.ibl_specular_textured PRIVATE glad::glad)
