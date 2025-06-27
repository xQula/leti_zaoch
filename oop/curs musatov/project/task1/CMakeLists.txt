cmake_minimum_required(VERSION 3.15.0)

include_guard(GLOBAL)

project(task1
        VERSION 0.0.1
        DESCRIPTION "curs task 1 for OOP"
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
        src/c++/transport/transportbase.cpp
        src/c++/transport/transportbase.h
        src/c++/transport/passengercar.cpp
        src/c++/transport/passengercar.h
        src/c++/transport/bus.cpp
        src/c++/transport/bus.h
        src/c++/transport/train.cpp
        src/c++/transport/train.h
        src/c++/transport/watervehicles.cpp
        src/c++/transport/watervehicles.h
        src/c++/transport/plane.cpp
        src/c++/transport/plane.h
        src/c++/Core/core.cpp
        src/c++/Core/core.h

)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++
)