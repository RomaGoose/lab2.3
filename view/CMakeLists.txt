add_library(view_lib STATIC
    mainwindow.cpp
    hanoi_widget.cpp
)

target_include_directories(view_lib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${LIBS_PATH}/sequence/include
    ${LIBS_PATH}/adapters/include
)

target_link_libraries(view_lib PRIVATE Qt6::Widgets)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR})