cmake_minimum_required(VERSION 3.12)

project(project1)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_compile_definitions(SOKOL_D3D11)

add_executable(project1 WIN32 project1.c)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT project1)
set_property(TARGET project1 PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
