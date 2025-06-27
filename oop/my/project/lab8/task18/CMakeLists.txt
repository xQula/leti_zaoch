cmake_minimum_required(VERSION 3.15.0)

include_guard(GLOBAL)

project(task18
        VERSION 0.0.1
        DESCRIPTION "task18 for OOP"
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
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/Bank/bankAccount.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/Bank/bankAccount.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/bank/accountType.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/bank/createAccount.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/bank/createAccount.h
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/bank/BankTransaction.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/bank/bankTransaction.h
)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/c++
)