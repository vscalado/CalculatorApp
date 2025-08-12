cmake_minimum_required(VERSION 3.16)
project(CalculatorAppLCM)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(yaml-cpp REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LCM REQUIRED lcm)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(${LCM_INCLUDE_DIRS})
link_directories(${LCM_LIBRARY_DIRS})

add_subdirectory(client)
add_subdirectory(server)