aux_source_directory (. SRC_LIST)

add_executable(2022 ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(2022 PRIVATE glfw)
target_link_libraries(2022 PRIVATE OpenGL::GL)
target_link_libraries(2022 PRIVATE glad::glad)
