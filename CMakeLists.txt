cmake_minimum_required(VERSION 3.28)
project(ApproxImageAlgoAdaptatif)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(ApproxImageAlgoAdaptatif main.cpp
        MainWindow.cpp
        MainWindow.h
        CustomGraphicsView.cpp
        CustomGraphicsView.h
        ImageProcessor.cpp
        ImageProcessor.h)
target_link_libraries(ApproxImageAlgoAdaptatif
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

