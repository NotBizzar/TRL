cmake_minimum_required(VERSION 3.27)
project(TEST)

file(GLOB_RECURSE TEST_SOURCES "./Src/*.c")

add_executable(Test ${TEST_SOURCES})
target_link_libraries(Test PRIVATE TRL)

target_include_directories(Test PRIVATE
  ../TotallyReliableLibrary/Include
)