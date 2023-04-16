aux_source_directory(. TEST_LIST)

add_executable(test ${TEST_LIST})

find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

target_link_libraries(test PRIVATE glfw)
target_link_libraries(test PRIVATE OpenGL::GL)
target_link_libraries(test PRIVATE glad::glad)
target_link_libraries(test PRIVATE fmt::fmt)

