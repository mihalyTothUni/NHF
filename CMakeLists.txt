cmake_minimum_required(VERSION 3.27)
project(NHF)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(-DMEMTRACE)

add_executable(NHF main.cpp
        database.h
        film.h
        family.h
        documentary.h
        memtrace.cpp
        memtrace.h
        gtest_lite.h
        database.cpp
        film.cpp
        family.cpp
        documentary.cpp
        fileHandler.h
        fileHandler.cpp)
