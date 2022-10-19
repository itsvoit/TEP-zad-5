cmake_minimum_required(VERSION 3.21)
project(TEP_zad_5)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(TEP_zad_5
        CMySmartPointer.h
        CTab.cpp
        CTab.h
        main.cpp)
