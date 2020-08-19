#
# Toolchain Requirements
#
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)

#
# Include and Link Directories
#
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

#
# Project - DAGSS
#
project(algo)

#
# 01 Data Structures - AHLBHUSQ
#

#
# 02 Algo Techniques - BDBGDB
#

#
# 03 Graph - BDKPBD
#
add_executable(graph_algo graph/main.cpp)
target_link_libraries(graph_algo boost_program_options)

#
# 04 Searching - BT
#

#
# 05 Sorting - ISBHMQ
#

