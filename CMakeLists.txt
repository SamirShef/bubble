cmake_minimum_required(VERSION 3.10)
project(bubble LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Compiler: ${CMAKE_C_COMPILER_ID}")
