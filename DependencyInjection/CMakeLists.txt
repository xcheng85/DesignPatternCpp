cmake_minimum_required(VERSION 3.8)

project(DI_test)

include_directories(${Boost_INCLUDE_DIRS})

set(HEADERS di.hpp)

set(SOURCES diDemo.cpp)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC gtest_main ${Boost_LIBRARIES})

add_executable(diDemo2 ${HEADERS} diDemo2.cpp)
target_link_libraries(diDemo2 PUBLIC gtest_main ${Boost_LIBRARIES})

add_executable(diHelloWorld ${HEADERS} diHelloWorld.cpp)
target_link_libraries(diHelloWorld PUBLIC gtest_main ${Boost_LIBRARIES})

add_executable(diBinding ${HEADERS} diBinding.cpp)
target_link_libraries(diBinding PUBLIC gtest_main ${Boost_LIBRARIES})

add_executable(diDynamicBinding ${HEADERS} diDynamicBinding.cpp)
target_link_libraries(diDynamicBinding PUBLIC gtest_main ${Boost_LIBRARIES})

add_executable(diCreatable ${HEADERS} diCreatable.cpp)
target_link_libraries(diCreatable PUBLIC gtest_main ${Boost_LIBRARIES})


install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ../bin)
install(TARGETS diDemo2 RUNTIME DESTINATION ../bin)
install(TARGETS diHelloWorld RUNTIME DESTINATION ../bin) 
install(TARGETS diBinding RUNTIME DESTINATION ../bin) 
install(TARGETS diDynamicBinding RUNTIME DESTINATION ../bin) 
install(TARGETS diCreatable RUNTIME DESTINATION ../bin) 