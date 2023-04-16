aux_source_directory (. SRC_LIST)

add_executable(4.2.lighting_maps_specular_map ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(4.2.lighting_maps_specular_map PRIVATE glfw)
target_link_libraries(4.2.lighting_maps_specular_map PRIVATE OpenGL::GL)
target_link_libraries(4.2.lighting_maps_specular_map PRIVATE glad::glad)
