aux_source_directory (. SRC_LIST)

add_executable(10.1.instancing_quads ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(10.1.instancing_quads PRIVATE glfw)
target_link_libraries(10.1.instancing_quads PRIVATE OpenGL::GL)
target_link_libraries(10.1.instancing_quads PRIVATE glad::glad)
