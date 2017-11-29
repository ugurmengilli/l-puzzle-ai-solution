cmake_minimum_required(VERSION 2.8.11)

project(LpuzzleAIsolution)

set(CMAKE_PREFIX_PATH "C:/Qt/5.9.1/msvc2015")	# To find Qt modules, add Qt direction

# Static library of Keyence Laser Scanner
add_subdirectory(ai-algorithms)

# Executable scanning application. Depends on all libs.
add_subdirectory(application)
