cmake_minimum_required(VERSION 3.15.0)

include_guard(GLOBAL)

project(task8
        VERSION 0.0.1
        DESCRIPTION "task8 for OOP"
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
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/core/Core.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/core/Core.h
        src/c++/read/ReadFile.cpp
        src/c++/read/ReadFile.h
        src/c++/sort/SortStr.cpp
        src/c++/sort/SortStr.h
)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++
)