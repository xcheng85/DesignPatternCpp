cmake_minimum_required(VERSION 3.8)

project(Interpreter)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(Interpreter main.cpp)

target_link_libraries(Interpreter PUBLIC gtest_main ${Boost_LIBRARIES})

install(TARGETS Interpreter RUNTIME DESTINATION ../bin)


