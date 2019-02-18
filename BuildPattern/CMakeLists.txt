cmake_minimum_required(VERSION 3.8)

project(Builder_test)

include_directories(${Boost_INCLUDE_DIRS})

set(HEADERS BuildPattern.hpp)

set(SOURCES BuildPatternTests.cpp)

add_executable(${PROJECT_NAME} 
${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC 
 gtest_main
 ${Boost_LIBRARIES}
 )

 add_test(
     NAME ${PROJECT_NAME}
     COMMAND ${PROJECT_NAME}
 )
 install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ../bin)
