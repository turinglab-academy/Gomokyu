cmake_minimum_required(VERSION 3.16)

project(Gomoku VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

# 💡 이 줄을 꼭 추가해야 qt_add_executable을 사용할 수 있음
qt_standard_project_setup()

set(PROJECT_SOURCES
    main.cpp
    gomokyuwindow.cpp
    gomokyuwindow.h
    gomokyuwindow.ui
    boardframe.h boardframe.cpp
    Gomoku.qrc
    wndsetting.h wndsetting.cpp wndsetting.ui
)

qt_add_executable(Gomoku
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    server.h server.cpp
    client.h client.cpp
    CommonService.h

)

target_include_directories(Gomoku PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Gomoku PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
)

qt_finalize_executable(Gomoku)
