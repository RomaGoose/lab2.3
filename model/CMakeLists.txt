add_library(model_lib STATIC
    # hanoi_model.cpp
)

target_include_directories(model_lib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${LIBS_PATH}/sequence/include
    ${LIBS_PATH}/adapters/include
)

target_link_libraries(model_lib PRIVATE Qt6::Widgets)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR})