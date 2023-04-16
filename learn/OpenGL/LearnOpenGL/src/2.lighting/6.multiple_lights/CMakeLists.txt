aux_source_directory (. SRC_LIST)

add_executable(6.multiple_lights ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(6.multiple_lights PRIVATE glfw)
target_link_libraries(6.multiple_lights PRIVATE OpenGL::GL)
target_link_libraries(6.multiple_lights PRIVATE glad::glad)
