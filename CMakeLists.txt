cmake_minimum_required(VERSION 3.23)
project(AED_Air)

set(CMAKE_CXX_STANDARD 14)

add_executable(AED_Air src/main.cpp src/Graph.cpp src/Graph.h src/Airline.cpp src/Airline.h src/Airport.cpp src/Airport.h src/CoordDistance.cpp src/CoordDistance.h src/Interface.cpp src/Interface.h src/Gestor.cpp src/Gestor.h)
