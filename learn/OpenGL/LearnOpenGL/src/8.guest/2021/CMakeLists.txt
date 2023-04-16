aux_source_directory (. SRC_LIST)

add_executable(2021 ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(2021 PRIVATE glfw)
target_link_libraries(2021 PRIVATE OpenGL::GL)
target_link_libraries(2021 PRIVATE glad::glad)
