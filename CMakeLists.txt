cmake_minimum_required(VERSION 3.15)

project(ProyectoIntegrador VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Opción para activar cobertura de código
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

# Fuentes principales
set(SOURCES
    main.cpp
    Video.cpp
    Pelicula.cpp
    Serie.cpp
    Episodio.cpp
)

add_executable(ProyectoIntegrador ${SOURCES})
target_include_directories(ProyectoIntegrador PRIVATE ${CMAKE_SOURCE_DIR})

# Descarga y configuración de GoogleTest
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.13.0.zip
)

# Para evitar problemas con tests en subdirectorios
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Buscar archivos de test en carpeta test
file(GLOB TEST_SOURCES "test/test_*.cpp")

# Crear ejecutable para tests
add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests PRIVATE GTest::gtest_main)
target_include_directories(runTests PRIVATE ${CMAKE_SOURCE_DIR})

# Detectar tests para ctest
include(GoogleTest)
gtest_discover_tests(runTests)
