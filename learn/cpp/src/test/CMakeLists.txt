aux_source_directory(. SRC_LIST)

string(FIND ${CMAKE_CURRENT_SOURCE_DIR} / idx REVERSE)
math(EXPR idx "${idx} + 1")
string(LENGTH ${CMAKE_CURRENT_SOURCE_DIR} len)
string(SUBSTRING ${CMAKE_CURRENT_SOURCE_DIR} ${idx} ${len} pre)

foreach (var ${SRC_LIST})
    string(LENGTH ${var} len)
    string(SUBSTRING ${var} 2 ${len} post)
    add_executable("${pre}_${post}" ${var} we.h)
endforeach ()


