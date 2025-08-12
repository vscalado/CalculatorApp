add_executable(CalculatorServer
    LCM/server.cpp
)

target_include_directories(CalculatorServer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../messages
)

target_link_libraries(CalculatorServer PRIVATE ${LCM_LIBRARIES})