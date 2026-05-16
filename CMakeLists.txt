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


add_subdirectory(model)
add_subdirectory(view)
add_subdirectory(controller)

qt_add_executable(hanoi main.cpp)

target_link_libraries(hanoi PRIVATE 
        Qt6::Widgets
        view_lib  
        controller_lib      
        model_lib
)


target_include_directories(hanoi PRIVATE
    libs/sequence/include
    libs/adapters/include
)



include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.7.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(tests
    libs/adapters/tests/stack_test.cpp
)

target_compile_options(tests PRIVATE -fsanitize=address,undefined)
target_link_options(tests PRIVATE -fsanitize=address,undefined)

target_include_directories(tests PRIVATE
    ${LIBS_PATH}/adapters/include
    ${LIBS_PATH}/sequence/include
)

target_link_libraries(tests PRIVATE
    Catch2::Catch2WithMain
)


enable_testing()

include(Catch)
catch_discover_tests(tests)