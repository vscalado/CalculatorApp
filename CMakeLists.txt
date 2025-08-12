#Teste
cmake_minimum_required(VERSION 3.5)

project(CalculatorApp)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(yaml-cpp REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(CalculatorApp
    main.cpp
    UI/MainWindow.cpp
    Logic/Calculator.cpp
    Persistence/Database.cpp
)

target_link_libraries(CalculatorApp Qt6::Widgets yaml-cpp)
