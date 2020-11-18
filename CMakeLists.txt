cmake_minimum_required(VERSION 3.8.2)

project(ttt-plusplus)

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Automatic cmake features
set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTORCC ON)

# Add a compiler flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Configure Qt
find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Link code
add_subdirectory(Src)
