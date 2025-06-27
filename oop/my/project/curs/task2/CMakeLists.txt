cmake_minimum_required(VERSION 3.15.0)

include_guard(GLOBAL)

project(curs2
        VERSION 0.0.1
        DESCRIPTION "curs2 for OOP"
        LANGUAGES C CXX
)

if(NOT CMAKE_CXX_STANDARD)
    message(STATUS "[${PROJECT_NAME}] setting c++ standard to c++23")
    set(CMAKE_CXX_STANDARD 23)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()



add_executable( ${PROJECT_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/main.cpp
        src/c++/algo/dijkstra.h
        src/c++/core/Core.cpp
        src/c++/core/Core.h
)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++
)