cmake_minimum_required(VERSION 3.16)
project(SingleResponsibilityPrinciple)

set(CMAKE_CXX_STANDARD 14)

add_executable(SingleResponsibilityPrinciple main.cpp)

find_package(Boost 1.72.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(BoostTest main.cpp)
target_link_libraries(BoostTest ${Boost_LIBRARIES})