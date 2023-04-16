aux_source_directory (. SRC_LIST)

add_executable(3.2d_game ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(3.2d_game PRIVATE glfw)
target_link_libraries(3.2d_game PRIVATE OpenGL::GL)
target_link_libraries(3.2d_game PRIVATE glad::glad)
