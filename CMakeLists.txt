cmake_minimum_required(VERSION 3.31)

# Make Project
project(Engine VERSION 1.0.0 LANGUAGES CXX C)

# Set CXX Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Source
add_subdirectory(src)
add_subdirectory(external/glfw)
add_subdirectory(external/glad)