cmake_minimum_required(VERSION 3.10)
project(ProyectoIntegrador)

set(CMAKE_CXX_STANDARD 17)

# Agrega tus fuentes
set(SOURCES
    main.cpp         
    Video.cpp
    Pelicula.cpp
    Serie.cpp
    Episodio.cpp
)

# Ejecutable principal
add_executable(ProyectoIntegrador ${SOURCES})

# Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Fuentes para tests (excluyendo main.cpp)
set(TEST_SOURCES
    test/test_main.cpp       
    test/test_episodio.cpp
    test/test_pelicula.cpp
    test/test_serie.cpp
    test/test_video.cpp
    Video.cpp
    Pelicula.cpp
    Serie.cpp
    Episodio.cpp
)

add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

add_test(NAME runTests COMMAND runTests)
