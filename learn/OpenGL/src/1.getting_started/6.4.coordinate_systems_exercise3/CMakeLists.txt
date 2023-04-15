aux_source_directory (. SRC_LIST)

add_executable(6.4.coordinate_systems_exercise3 ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(6.4.coordinate_systems_exercise3 PRIVATE glfw)
target_link_libraries(6.4.coordinate_systems_exercise3 PRIVATE OpenGL::GL)
target_link_libraries(6.4.coordinate_systems_exercise3 PRIVATE glad::glad)
