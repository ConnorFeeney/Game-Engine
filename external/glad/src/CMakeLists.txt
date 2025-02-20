add_library(glad STATIC "glad.c" "../include/glad/glad.h")

target_include_directories(glad PUBLIC ../include)