cmake_minimum_required(VERSION 3.5)
project(Parcial)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Nodo.h Nodo.cpp Cola.cpp Cola.h Pila.cpp Pila.h Lista.h Lista.cpp main2.cpp)
add_executable(Parcial ${SOURCE_FILES})