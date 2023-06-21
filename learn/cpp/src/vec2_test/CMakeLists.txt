add_executable(vec2_test main.cpp vec2.cpp)

target_link_libraries(vec2_test libgtest.a libgtest_main.a libgmock.a libgmock_main.a)