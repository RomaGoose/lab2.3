add_library(controller_lib STATIC
    game_controller.cpp
    settings_controller.cpp
    main_controller.cpp
)

target_include_directories(controller_lib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${LIBS_PATH}/sequence/include
    ${LIBS_PATH}/adapters/include
)

target_link_libraries(controller_lib PRIVATE 
    Qt6::Widgets
    view_lib  
    model_lib
)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR})