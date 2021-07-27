cmake_minimum_required(VERSION 3.17)
project(AlgoProj)

set(CMAKE_CXX_STANDARD 14)

add_executable(AlgoProj main.cpp DataStructers/Graph.cpp DataStructers/Graph.h DataStructers/Queue.cpp DataStructers/Queue.h DataStructers/Vertex.h configs.h DataStructers/List.cpp DataStructers/List.h Algorhitms.cpp Algorhitms.h)