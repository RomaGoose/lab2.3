add_library(view_lib STATIC
    mainwindow.cpp
)

target_include_directories(view_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(view_lib PRIVATE Qt6::Widgets)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR})