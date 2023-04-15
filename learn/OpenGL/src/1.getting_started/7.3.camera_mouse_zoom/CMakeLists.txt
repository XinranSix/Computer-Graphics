aux_source_directory (. SRC_LIST)

add_executable(7.3.camera_mouse_zoom ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(7.3.camera_mouse_zoom PRIVATE glfw)
target_link_libraries(7.3.camera_mouse_zoom PRIVATE OpenGL::GL)
target_link_libraries(7.3.camera_mouse_zoom PRIVATE glad::glad)
