cmake_minimum_required(VERSION 3.15)

include_guard(GLOBAL)

project(lab2
        LANGUAGES CXX
        VERSION 0.6.0
)

set(PROJECT_NAMESPACE ${PROJECT_NAME}::)

set(COMPANY "Maksimov")
set(COPYRIGHT "Copyright (c) 2024 ${COMPANY}. All rights reserved.")
set(IDENTIFIER "${PROJECT_NAME}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(STATIC_COMPILE TRUE)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Gui
        Widgets
)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
        PRIVATE
        src/c++/main.cc
        src/c++/grafic/bizye.cc
                src/c++/grafic/bizye.h
        src/c++/grafic/mainwindow.cc
        src/c++/grafic/mainwindow.h
        src/c++/grafic/moveitem.cc
        src/c++/grafic/moveitem.h
)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        POSITION_INDEPENDENT_CODE ON
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Widgets
)

target_compile_definitions(${PROJECT_NAME}
        PUBLIC
        -DPROJECT_NAME="${PROJECT_NAME}"
        -DPROJECT_VERSION="${PROJECT_VERSION}"
        -DPROJECT_COMPANY="${COMPANY}"
)
