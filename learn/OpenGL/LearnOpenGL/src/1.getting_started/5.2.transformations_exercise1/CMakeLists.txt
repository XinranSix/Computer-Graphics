aux_source_directory (. SRC_LIST)

add_executable(5.2.transformations_exercise1 ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(5.2.transformations_exercise1 PRIVATE glfw)
target_link_libraries(5.2.transformations_exercise1 PRIVATE OpenGL::GL)
target_link_libraries(5.2.transformations_exercise1 PRIVATE glad::glad)
