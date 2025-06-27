cmake_minimum_required(VERSION 3.15)

include_guard(GLOBAL)

project(lab1
	LANGUAGES CXX
	VERSION 0.6.0
)

set(PROJECT_NAMESPACE ${PROJECT_NAME}::)

set(COMPANY "Maksimov")
set(COPYRIGHT "Copyright (c) 2024 ${COMPANY}. All rights reserved.")
set(IDENTIFIER "${PROJECT_NAME}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
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
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/main.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/graphic/drawField.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/graphic/mainWindow.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/graphic/settingPanel.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/shapes/sCircle.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/shapes/sLine.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/shapes/sOriginPlane.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/shapes/sPoint.cc
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/graphic/drawField.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/graphic/mainWindow.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/graphic/settingPanel.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/shapes/sCircle.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/shapes/sLine.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/shapes/sOriginPlane.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/c++/shapes/sPoint.h

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
