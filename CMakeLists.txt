cmake_minimum_required(VERSION 3.16)
project(pepa)

set(CMAKE_CXX_STANDARD 14)

add_executable(pepa main.cpp Question.cpp Question.h FileManager.cpp FileManager.h Answer.cpp Answer.h Quiz.h Quiz.cpp)