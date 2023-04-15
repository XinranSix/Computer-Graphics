aux_source_directory (. SRC_LIST)

add_executable(4.4.lighting_maps_exercise4 ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(4.4.lighting_maps_exercise4 PRIVATE glfw)
target_link_libraries(4.4.lighting_maps_exercise4 PRIVATE OpenGL::GL)
target_link_libraries(4.4.lighting_maps_exercise4 PRIVATE glad::glad)
