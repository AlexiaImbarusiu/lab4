cmake_minimum_required(VERSION 3.15)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab4 main.cpp Controller.cpp Controller.h Medikament.cpp Medikament.h Repository.cpp Repository.h Test.cpp Test.h UI.cpp UI.h)