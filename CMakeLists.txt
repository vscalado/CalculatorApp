cmake_minimum_required(VERSION 3.16)
project(CalculatorApp)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(yaml-cpp REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(CalculatorApp
    main.cpp
    UI/MainWindow.cpp
    Logic/Calculator.cpp
    Persistence/Database.cpp
)

target_include_directories(CalculatorApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/UI
    ${CMAKE_CURRENT_SOURCE_DIR}/Logic
    ${CMAKE_CURRENT_SOURCE_DIR}/Persistence
    ${CMAKE_CURRENT_SOURCE_DIR}/Model
)

target_link_libraries(CalculatorApp PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets yaml-cpp)
