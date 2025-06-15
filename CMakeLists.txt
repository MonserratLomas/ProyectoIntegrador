cmake_minimum_required(VERSION 3.30)

project(ProyectoIntegrador VERSION 1.0.0 LANGUAGES CXX)

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

# Archivos fuente del proyecto
set(SOURCES
    main.cpp
    Video.cpp
    Pelicula.cpp
    Serie.cpp
    Episodio.cpp
)

# Crear el ejecutable
add_executable(ProyectoIntegrador ${SOURCES})

# Directorio raíz donde están los headers
target_include_directories(ProyectoIntegrador PRIVATE ${CMAKE_SOURCE_DIR})
