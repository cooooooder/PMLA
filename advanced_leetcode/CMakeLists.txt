include_directories(include src/stdafx)

file(GLOB lib_source_files "src/*.cpp")
file(GLOB test_source_files "test/*.cpp")


add_library(advanced_leetcode ${lib_source_files})

add_executable(advanced_leetcode_test ${test_source_files} ${CMAKE_CXX_COMPLIER})

target_link_libraries(advanced_leetcode_test advanced_leetcode)