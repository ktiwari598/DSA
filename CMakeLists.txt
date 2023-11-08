cmake_minimum_required(VERSION 3.26)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSA Maths/gcd_lcm.cpp)
add_executable(new_target Maths/prime_numbers.cpp)
add_executable(factorial Maths/factorial.cpp)
add_executable(combinations Maths/Combinations.cpp)
add_executable(modularecponentiation Maths/ModularExponentiation.cpp)
