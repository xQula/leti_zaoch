cmake_minimum_required(VERSION 3.15)

include_guard(GLOBAL)

project(lab4
        VERSION 0.0.1
        DESCRIPTION "Set your description"
        LANGUAGES C CXX
)

if(NOT CMAKE_CXX_STANDARD)
    message(STATUS "[${PROJECT_NAME}] setting c++ standard to c++20")
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

if("${CMAKE_GENERATOR}" MATCHES "^Visual Studio")
    set(CMAKE_GENERATOR_PLATFORM "x64" CACHE STRING "" FORCE)
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)


add_executable(${PROJECT_NAME})
add_executable(${PROJECT_NAME}_second)

target_sources(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/main.cc
)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++
)

target_sources(${PROJECT_NAME}_second
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/second_main.cc
)

target_include_directories(${PROJECT_NAME}_second
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++
)

message(STATUS "[${PROJECT_NAME}] setting metadata definitions:")
message(STATUS "[${PROJECT_NAME}] - PROJECT_NAME: ${PROJECT_NAME}")
message(STATUS "[${PROJECT_NAME}] - PROJECT_VERSION: ${PROJECT_VERSION}")
message(STATUS "[${PROJECT_NAME}] configuring ${PROJECT_NAME} done! ")