cmake_minimum_required(VERSION 3.20)

project(StrUtils
    VERSION 1.0
    LANGUAGES CXX
)

add_library(strutils INTERFACE)

target_include_directories(strutils INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)