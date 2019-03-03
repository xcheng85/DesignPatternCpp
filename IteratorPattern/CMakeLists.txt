cmake_minimum_required(VERSION 3.8)

project(IteratorPattern)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(Iter_example1 example1.cpp)

target_link_libraries(Iter_example1 PUBLIC gtest_main ${Boost_LIBRARIES})

add_executable(Iter_test iter_test.cpp)
target_link_libraries(Iter_test PUBLIC gtest_main ${Boost_LIBRARIES})

add_executable(Iter_example2 example2.cpp)
target_link_libraries(Iter_example2 PUBLIC gtest_main ${Boost_LIBRARIES})

install(TARGETS Iter_example1 RUNTIME DESTINATION ../bin)
install(TARGETS Iter_test RUNTIME DESTINATION ../bin)
install(TARGETS Iter_example2 RUNTIME DESTINATION ../bin)
