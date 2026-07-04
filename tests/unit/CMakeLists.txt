add_executable(unit_tests "test.cpp")

target_link_libraries(unit_tests PRIVATE xgpu Catch2::Catch2WithMain)