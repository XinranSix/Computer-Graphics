aux_source_directory (. SRC_LIST)

add_executable(5.4.light_casters_spot_soft ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(5.4.light_casters_spot_soft PRIVATE glfw)
target_link_libraries(5.4.light_casters_spot_soft PRIVATE OpenGL::GL)
target_link_libraries(5.4.light_casters_spot_soft PRIVATE glad::glad)
