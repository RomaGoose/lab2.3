cmake_minimum_required(VERSION 3.16)

project(lab3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/qt_forms)

set(PROJECT_SOURCES
        main.cpp
        src/mainwindow.cpp
        include/mainwindow.h
        qt_forms/mainwindow.ui
)

qt_add_executable(lab3 ${PROJECT_SOURCES})

target_include_directories(lab3 PRIVATE
    include
)

target_link_libraries(lab3 PRIVATE 
        Qt6::Widgets)