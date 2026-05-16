cmake_minimum_required(VERSION 3.16)

project(hanoi VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBS_PATH ${PROJECT_SOURCE_DIR}/libs)

find_package(Qt6 REQUIRED COMPONENTS Widgets)


add_subdirectory(view)

qt_add_executable(hanoi main.cpp)

target_link_libraries(hanoi PRIVATE 
        Qt6::Widgets
        view_lib        
)


target_include_directories(hanoi PRIVATE
    libs/sequence/include
    libs/adapters/include
)
