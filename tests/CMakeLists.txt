cmake_minimum_required(VERSION 3.0)
project(tests)
enable_testing()

add_executable(prim_test test.cpp)
target_link_libraries(prim_test PUBLIC listbase)
target_include_directories(prim_test PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/base"
                          )

add_test(NAME prim_test COMMAND prim_test)