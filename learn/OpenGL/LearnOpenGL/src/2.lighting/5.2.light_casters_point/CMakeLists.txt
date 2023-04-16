aux_source_directory (. SRC_LIST)

add_executable(5.2.light_casters_point ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(5.2.light_casters_point PRIVATE glfw)
target_link_libraries(5.2.light_casters_point PRIVATE OpenGL::GL)
target_link_libraries(5.2.light_casters_point PRIVATE glad::glad)
