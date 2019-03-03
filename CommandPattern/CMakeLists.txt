cmake_minimum_required(VERSION 3.8)

project(CommandPattern)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(simple_commands simple_commands.cpp)
add_executable(macro_commands macro_commands.cpp)

target_link_libraries(simple_commands PUBLIC gtest_main ${Boost_LIBRARIES})
target_link_libraries(macro_commands PUBLIC gtest_main ${Boost_LIBRARIES})

install(TARGETS simple_commands macro_commands RUNTIME DESTINATION ../bin)


