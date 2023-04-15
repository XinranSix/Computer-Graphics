aux_source_directory (. SRC_LIST)

add_executable(2.stencil_testing ${SRC_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(2.stencil_testing PRIVATE glfw)
target_link_libraries(2.stencil_testing PRIVATE OpenGL::GL)
target_link_libraries(2.stencil_testing PRIVATE glad::glad)
