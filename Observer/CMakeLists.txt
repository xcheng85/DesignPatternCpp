cmake_minimum_required(VERSION 3.8)

project(Observer)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(Observer_example1 example1.cpp)
target_link_libraries(Observer_example1 PUBLIC gtest_main ${Boost_LIBRARIES})
install(TARGETS Observer_example1 RUNTIME DESTINATION ../bin)

add_executable(Observer_example2 example2.cpp)
target_link_libraries(Observer_example2 PUBLIC gtest_main ${Boost_LIBRARIES})
install(TARGETS Observer_example2 RUNTIME DESTINATION ../bin)





add_executable(Observer_test observer_test.cpp)
target_link_libraries(Observer_test PUBLIC gtest_main ${Boost_LIBRARIES})
install(TARGETS Observer_test RUNTIME DESTINATION ../bin)
