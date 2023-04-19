aux_source_directory(. SRC_LIST)

add_executable(1.2.hello_window_clear ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

target_link_libraries(1.2.hello_window_clear PRIVATE glfw)
target_link_libraries(1.2.hello_window_clear PRIVATE OpenGL::GL)
target_link_libraries(1.2.hello_window_clear PRIVATE glad::glad)
target_link_libraries(1.2.hello_window_clear PRIVATE imgui::imgui)
