cmake_minimum_required(VERSION 3.20)
project(CPractic C)

set(CMAKE_C_STANDARD 99)

add_executable(CPractic main.c solve_equation.c test.c)
target_link_libraries(CPractic m)
