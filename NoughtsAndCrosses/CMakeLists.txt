# cmake_minimum_required(VERSION <specify CMake version here>)
project(Noughts_and_Crosses)

set(CMAKE_CXX_STANDARD 20)

add_executable(Noughts_and_Crosses main.cpp PlayField.h TreeNode.h PlayField.cpp TreeNode.cpp)