cmake_minimum_required(VERSION 3.10)
project(RunTests)

# GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Archivos fuente de test (ojo: no incluir main.cpp del proyecto principal)
set(TEST_SOURCES
    test_episodio.cpp
    test_main.cpp      # este main para tests
    test_pelicula.cpp
    test_serie.cpp
    test_video.cpp
    ../Video.cpp       # agregar .cpp de clases que se usan en los tests
    ../Pelicula.cpp
    ../Serie.cpp
    ../Episodio.cpp
)

add_executable(runTests ${TEST_SOURCES})

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

add_test(NAME runTests COMMAND runTests)
