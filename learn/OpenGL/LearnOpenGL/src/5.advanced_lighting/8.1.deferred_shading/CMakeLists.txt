aux_source_directory (. SRC_LIST)

add_executable(8.1.deferred_shading ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(8.1.deferred_shading PRIVATE glfw)
target_link_libraries(8.1.deferred_shading PRIVATE OpenGL::GL)
target_link_libraries(8.1.deferred_shading PRIVATE glad::glad)
