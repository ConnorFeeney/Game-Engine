file(GLOB SOURCES *.cpp)

add_executable(Engine ${SOURCES})

find_package(OpenGL REQUIRED)

target_include_directories(Engine PRIVATE ${OPENGL_INCLUDE_DIR})
target_include_directories(Engine PRIVATE ../include)
target_include_directories(Engine PRIVATE ../external/glfw/include)
target_include_directories(Engine PRIVATE ../external/glad/include/glad)
target_include_directories(Engine PRIVATE ../external/glad/include/KHR)

target_link_libraries(Engine glfw)
target_link_libraries(Engine glad)
target_link_libraries(Engine ${OPENGL_LIBRARIES})