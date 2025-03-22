file(GLOB_RECURSE SOURCES "*.cpp" "*.c" "*.h")

add_executable(Engine ${SOURCES})

find_package(OpenGL REQUIRED)

target_include_directories(Engine PRIVATE ${OPENGL_INCLUDE_DIR})
target_include_directories(Engine PRIVATE ../external/glfw/include)
target_include_directories(Engine PRIVATE ../external/glad/include/glad)
target_include_directories(Engine PRIVATE ../external/glad/include/KHR)

target_include_directories(Engine PRIVATE ${CMAKE_SOURCE_DIR}/src/math)
target_include_directories(Engine PRIVATE ${CMAKE_SOURCE_DIR}/src/graphics)
target_include_directories(Engine PRIVATE ${CMAKE_SOURCE_DIR}/src/shader)
target_include_directories(Engine PRIVATE ${CMAKE_SOURCE_DIR}/src/thread)

target_link_libraries(Engine glfw)
target_link_libraries(Engine glad)
target_link_libraries(Engine ${OPENGL_LIBRARIES})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_custom_command(
        TARGET Engine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/shaders
                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/shaders
    ) 
endif()