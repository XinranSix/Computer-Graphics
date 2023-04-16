aux_source_directory (. SRC_LIST)

add_executable(7.4.camera_class ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(7.4.camera_class PRIVATE glfw)
target_link_libraries(7.4.camera_class PRIVATE OpenGL::GL)
target_link_libraries(7.4.camera_class PRIVATE glad::glad)
