add_executable(test1 main.cpp)

target_link_libraries(test1 libboost_coroutine.a libboost_container.a libboost_context.a)