aux_source_directory(. SRC_LIST)

foreach (var ${SRC_LIST})
    string(LENGTH ${var} len)
    string(SUBSTRING ${var} 2 ${len} tmp)
    math(EXPR idx "${len} - 4")
    string(SUBSTRING ${tmp} 0 ${idx} real)
    add_executable("${real}" ${real})
endforeach ()
