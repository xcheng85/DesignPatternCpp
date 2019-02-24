cmake_minimum_required(VERSION 3.8)

project(RAII)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(HeapWrapper HeapWrapper.hpp HeapTest.cpp)
target_link_libraries(HeapWrapper PUBLIC gtest_main ${Boost_LIBRARIES})

install(TARGETS HeapWrapper RUNTIME DESTINATION ../bin)
