add_executable(test1 main.cpp)

target_link_libraries(test1 libgtest.a libgtest_main.a libgmock.a libgmock_main.a)