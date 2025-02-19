file(GLOB SOURCES *.cpp)

add_executable(Engine ${SOURCES})
target_include_directories(Engine PRIVATE ../include)