aux_source_directory (. SRC_LIST)

add_executable(6.2.cubemaps_environment_mapping ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(6.2.cubemaps_environment_mapping PRIVATE glfw)
target_link_libraries(6.2.cubemaps_environment_mapping PRIVATE OpenGL::GL)
target_link_libraries(6.2.cubemaps_environment_mapping PRIVATE glad::glad)
