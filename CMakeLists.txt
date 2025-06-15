cmake_minimum_required(VERSION 3.14)

project(ProyectoIntegrador VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --------------------------
# Archivos fuente del proyecto principal
# --------------------------
set(SOURCES
    main.cpp
    Video.cpp
    Pelicula.cpp
    Serie.cpp
    Episodio.cpp
)

add_executable(ProyectoIntegrador ${SOURCES})
target_include_directories(ProyectoIntegrador PRIVATE ${CMAKE_SOURCE_DIR})


# --------------------------
# GoogleTest
# --------------------------
# Cambia 1.17.0 si ves otra versión en /opt/homebrew/Cellar/googletest/
set(GTEST_ROOT /opt/homebrew/Cellar/googletest/1.17.0)
find_package(GTest REQUIRED PATHS ${GTEST_ROOT}/lib/cmake/GTest)

enable_testing()

# Buscar todos los archivos test/test_*.cpp
file(GLOB TEST_SOURCES "test/test_*.cpp")

add_executable(runTests ${TEST_SOURCES})
target_include_directories(runTests PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(runTests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)
