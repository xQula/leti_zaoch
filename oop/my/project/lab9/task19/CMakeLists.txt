cmake_minimum_required(VERSION 3.15.0)

include_guard(GLOBAL)

project(task19
        VERSION 0.0.1
        DESCRIPTION "task19 for OOP"
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
        src/c++/detail/detail.cpp
        src/c++/detail/detail.h
        src/c++/detail/wheel.cpp
        src/c++/detail/wheel.h
        src/c++/detail/engine.cpp
        src/c++/detail/engine.h
        src/c++/detail/transmission.cpp
        src/c++/detail/transmission.h
        src/c++/detail/body.cpp
        src/c++/detail/body.h
        src/c++/car/car.cpp
        src/c++/car/car.h
        src/c++/car/sportcar.cpp
        src/c++/car/sportcar.h
        src/c++/car/racingcar.cpp
        src/c++/car/racingcar.h
        src/c++/factory/factorycar.cpp
        src/c++/factory/factorycar.h
)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++
)