cmake_minimum_required(VERSION 3.15.0)

include_guard(GLOBAL)

project(task3
        VERSION 0.0.1
        DESCRIPTION "curs task3 for OOP"
        LANGUAGES C CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
if(NOT CMAKE_CXX_STANDARD)
    message(STATUS "[${PROJECT_NAME}] setting c++ standard to c++23")
    set(CMAKE_CXX_STANDARD 23)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

find_package(QT NAMES Qt5 COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS  Core )


add_executable( ${PROJECT_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/main.cpp
        src/c++/ship/ship.cpp
        src/c++/ship/ship.h
        src/c++/factory/factory.cpp
        src/c++/factory/factory.h
        src/c++/port/port.cpp
        src/c++/port/port.h
        src/c++/ship/queueship.cpp
        src/c++/ship/queueship.h
        src/c++/utils/random.cpp
        src/c++/utils/random.h
        src/c++/utils/writer.cpp
        src/c++/utils/writer.h

)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++
)

target_link_libraries(${PROJECT_NAME}
        Qt${QT_VERSION_MAJOR}::Core
)
