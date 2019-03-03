cmake_minimum_required(VERSION 3.8)

project(Decorator)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(ProxyTest ProxyTest.cpp)
target_link_libraries(ProxyTest PUBLIC gtest_main ${Boost_LIBRARIES})

install(TARGETS ProxyTest RUNTIME DESTINATION ../bin)
