file(GLOB SOURCES *.cpp)

add_executable(Engine ${SOURCES})

target_include_directories(Engine PRIVATE ../include)
target_include_directories(Engine PRIVATE ../external/glfw/include)
target_include_directories(Engine PRIVATE ../external/glad/include/glad)
target_include_directories(Engine PRIVATE ../external/glad/include/KHR)

target_link_libraries(Engine glfw)
target_link_libraries(Engine glad)
