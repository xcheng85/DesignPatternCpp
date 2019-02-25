cmake_minimum_required(VERSION 3.8)

project(Decorator)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(Decorator decoratorTest.cpp)
target_link_libraries(Decorator PUBLIC gtest_main ${Boost_LIBRARIES})

install(TARGETS Decorator RUNTIME DESTINATION ../bin)
