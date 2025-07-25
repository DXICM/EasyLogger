add_library(easylogger
    src/elog.c
    src/elog_async.c
    src/elog_buf.c
    src/elog_utils.c
    ../demo/os/linux/easylogger/port/elog_port.c
    ../demo/os/linux/easylogger/port/elog_file_port.c
    plugins/file/elog_file.c
)

target_include_directories(easylogger PUBLIC
    ../demo/os/linux/easylogger/inc
    inc
    plugins/file
)

target_link_libraries(easylogger PUBLIC pthread)
