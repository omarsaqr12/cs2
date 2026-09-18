cmake_minimum_required(VERSION 3.16)
project(cs2_nearest_centroid LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(cs2_core Point.cpp Classification.cpp)
target_include_directories(cs2_core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(cs2_demo "c++.cpp")
target_link_libraries(cs2_demo PRIVATE cs2_core)

enable_testing()
add_executable(cs2_tests tests/test_classification.cpp)
target_link_libraries(cs2_tests PRIVATE cs2_core)
add_test(NAME point_and_classification COMMAND cs2_tests)
add_test(NAME sample_output COMMAND cs2_demo)
set_tests_properties(sample_output PROPERTIES
    PASS_REGULAR_EXPRESSION "Query 20 \\(.*\\) -> [AB]")
