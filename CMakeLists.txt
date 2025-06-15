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

# Archivos fuente del proyecto
set(SOURCES
    main.cpp
    Video.cpp
    Pelicula.cpp
    Serie.cpp
    Episodio.cpp
)

add_executable(ProyectoIntegrador ${SOURCES})
target_include_directories(ProyectoIntegrador PRIVATE ${CMAKE_SOURCE_DIR})

# ----------------------------------------------------------
# CONFIGURACIÓN DE GOOGLE TEST
# ----------------------------------------------------------

# Buscar GoogleTest instalado en el sistema
find_package(GTest REQUIRED)

# Añadir los archivos de test (ajusta las rutas si están en carpeta 'test')
set(TEST_SOURCES
    test/test_episodio.cpp
    test/test_pelicula.cpp
    test/test_serie.cpp
    test/test_video.cpp
)

add_executable(runTests ${TEST_SOURCES})

# Incluye directorios de headers
target_include_directories(runTests PRIVATE ${CMAKE_SOURCE_DIR})

# Enlaza con GoogleTest y pthread (en Linux/macOS)
target_link_libraries(runTests PRIVATE GTest::gtest_main pthread)

# Habilita tests para CTest
include(GoogleTest)
gtest_discover_tests(runTests)
