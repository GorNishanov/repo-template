add_executable(tests
    conqueue.test.cpp
    )
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain conqueue fmt)
catch_discover_tests(tests)
