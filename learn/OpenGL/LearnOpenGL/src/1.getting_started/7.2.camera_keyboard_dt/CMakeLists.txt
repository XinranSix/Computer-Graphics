aux_source_directory (. SRC_LIST)

add_executable(7.2.camera_keyboard_dt ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(7.2.camera_keyboard_dt PRIVATE glfw)
target_link_libraries(7.2.camera_keyboard_dt PRIVATE OpenGL::GL)
target_link_libraries(7.2.camera_keyboard_dt PRIVATE glad::glad)
