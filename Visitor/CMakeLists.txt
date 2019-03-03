cmake_minimum_required(VERSION 3.8)

project(Visitor)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(Visitor_example1 example1.cpp)
target_link_libraries(Visitor_example1 PUBLIC gtest_main ${Boost_LIBRARIES})
install(TARGETS Visitor_example1 RUNTIME DESTINATION ../bin)

add_executable(Visitor_example2 example1.cpp)
target_link_libraries(Visitor_example2 PUBLIC gtest_main ${Boost_LIBRARIES})
install(TARGETS Visitor_example2 RUNTIME DESTINATION ../bin)