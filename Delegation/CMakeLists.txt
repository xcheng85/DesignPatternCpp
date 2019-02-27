cmake_minimum_required(VERSION 3.8)

project(Delegation)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} Delegate.hpp Dispatcher.hpp FunctionDispatcher.hpp main.cpp Utils.hpp)

target_link_libraries(${PROJECT_NAME} PUBLIC 
 gtest_main
 ${Boost_LIBRARIES}
 )

 add_test(
     NAME ${PROJECT_NAME}
     COMMAND ${PROJECT_NAME}
 )
 install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ../bin)
