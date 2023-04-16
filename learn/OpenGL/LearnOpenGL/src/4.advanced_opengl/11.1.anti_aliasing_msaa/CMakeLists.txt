aux_source_directory (. SRC_LIST)

add_executable(11.1.anti_aliasing_msaa ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(11.1.anti_aliasing_msaa PRIVATE glfw)
target_link_libraries(11.1.anti_aliasing_msaa PRIVATE OpenGL::GL)
target_link_libraries(11.1.anti_aliasing_msaa PRIVATE glad::glad)
