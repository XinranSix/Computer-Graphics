aux_source_directory (. SRC_LIST)

add_executable(11.2.anti_aliasing_offscreen ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(11.2.anti_aliasing_offscreen PRIVATE glfw)
target_link_libraries(11.2.anti_aliasing_offscreen PRIVATE OpenGL::GL)
target_link_libraries(11.2.anti_aliasing_offscreen PRIVATE glad::glad)
