cmake_minimum_required(VERSION 3.30)

project(ProyectoIntegrador VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_COVERAGE "Enable code coverage flags" OFF)

if(ENABLE_COVERAGE)
    message(STATUS "Code coverage enabled")
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        add_compile_options(-fprofile-arcs -ftest-coverage -O0)
        add_link_options(-fprofile-arcs -ftest-coverage)
    else()
        message(WARNING "Coverage enabled but compiler not supported for coverage flags")
    endif()
endif()

set(SOURCES
    main.cpp
    Video.cpp
    Pelicula.cpp
    Serie.cpp
    Episodio.cpp
)

add_executable(ProyectoIntegrador ${SOURCES})

target_include_directories(ProyectoIntegrador PRIVATE ${CMAKE_SOURCE_DIR})

# --- Aquí empieza la configuración para tests ---

enable_testing()

# Suponiendo que usas GoogleTest, lo puedes descargar así (si no lo tienes ya)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Lista de archivos test
set(TEST_SOURCES
    test/test_episodio.cpp
    test/test_pelicula.cpp
    test/test_serie.cpp
    test/test_video.cpp
)

add_executable(tests ${TEST_SOURCES})

target_link_libraries(tests gtest_main)

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR})

add_test(NAME all_tests COMMAND tests)
