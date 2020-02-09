cmake_minimum_required(VERSION 3.15)
project(dark_tower)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/cxxopts/include)

add_executable(dark_tower_cli src/cli/main.cpp src/emu/dark_tower_interface.h src/emu/rom.cpp src/emu/rom.h src/emu/tms1400.cpp src/emu/tms1400.h src/emu/dark_tower.cpp src/emu/dark_tower.h)
