cmake_minimum_required(VERSION 3.5)

project(demo1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(demo1 main.cpp CommandLineParser.h CommandLineParser.cpp shellExecutor.h shellExecutor.cpp)

install(TARGETS demo1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
