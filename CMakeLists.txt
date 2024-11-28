cmake_minimum_required(VERSION 3.30)
project(MineSweeper)

set(CMAKE_CXX_STANDARD 26)

# Include SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(MineSweeper main.cpp
        Game.cpp
        Game.h
        Cell.cpp
        Cell.h
        Grid.cpp
        Grid.h
        Constants.h)

# Link SFML libraries
target_link_libraries(MineSweeper sfml-graphics sfml-window sfml-system)

add_custom_command(
        TARGET MineSweeper POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:MineSweeper>/resources
)
