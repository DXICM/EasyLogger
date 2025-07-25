add_executable(example
    main.c
    module_a/module_a.c
    module_b/module_b.c
)

target_link_libraries(example easylogger pthread)
