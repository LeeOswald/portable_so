cmake_minimum_required(VERSION 3.20)
project(console VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    set(ER_WINDOWS TRUE)
elseif(UNIX AND NOT APPLE)
    set(ER_LINUX TRUE)
else()
    message(FATAL_ERROR "Unsupported OS")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/a")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory(so)
add_subdirectory(exe)

