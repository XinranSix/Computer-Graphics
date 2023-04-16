aux_source_directory (. SRC_LIST)

add_executable(5.1.framebuffers ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(5.1.framebuffers PRIVATE glfw)
target_link_libraries(5.1.framebuffers PRIVATE OpenGL::GL)
target_link_libraries(5.1.framebuffers PRIVATE glad::glad)
