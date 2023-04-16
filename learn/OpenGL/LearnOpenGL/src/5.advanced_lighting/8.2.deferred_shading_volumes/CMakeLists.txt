aux_source_directory (. SRC_LIST)

add_executable(8.2.deferred_shading_volumes ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(8.2.deferred_shading_volumes PRIVATE glfw)
target_link_libraries(8.2.deferred_shading_volumes PRIVATE OpenGL::GL)
target_link_libraries(8.2.deferred_shading_volumes PRIVATE glad::glad)
