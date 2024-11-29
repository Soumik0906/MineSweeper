cmake_minimum_required(VERSION 3.28)
project(MineSweeper)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
        src/main.cpp
        src/Cell.cpp
        src/Grid.cpp
        src/Game.cpp
)

include_directories(include)

# Include SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(MineSweeper ${SOURCES})

# Link SFML libraries
target_link_libraries(MineSweeper sfml-graphics sfml-window sfml-system)