cmake_minimum_required(VERSION 3.2)
project(MPAGSCypher VERSION 0.1.0)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
add_executable(mpags-cypher 
		mpags-cipher.cpp
		MPAGSCipher/TransformChar.cpp
		MPAGSCipher/TransformChar.hpp
		MPAGSCipher/processCommandLine.cpp
		MPAGSCipher/processCommandLine.hpp)
set(CMAKE_CXX_EXTENSION OFF)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic") 
target_include_directories(mpags-cypher PRIVATE MPAGSCipher)
target_compile_features(mpags-cypher PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization)

