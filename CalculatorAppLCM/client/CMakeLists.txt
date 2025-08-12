add_executable(CalculatorApp
    main.cpp
    UI/MainWindow.cpp
)

target_include_directories(CalculatorApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/UI
    ${CMAKE_CURRENT_SOURCE_DIR}/../messages
)

target_link_libraries(CalculatorApp PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets ${LCM_LIBRARIES})