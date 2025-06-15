cmake_minimum_required(VERSION 3.10)
project(ProyectoIntegrador VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(ENABLE_COVERAGE "Enable coverage reporting" OFF)

if(ENABLE_COVERAGE)
    message(STATUS "Coverage enabled")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(--coverage -O0 -g)
        add_link_options(--coverage)
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

# Incluir la carpeta raíz para los includes
target_include_directories(ProyectoIntegrador PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Configuración para GoogleTest
enable_testing()
find_package(GTest REQUIRED)

# Archivos fuente de tests
set(TEST_SOURCES
    test/test_video.cpp
    test/test_pelicula.cpp
    test/test_serie.cpp
    test/test_episodio.cpp
)

add_executable(runTests ${TEST_SOURCES})

target_link_libraries(runTests PRIVATE GTest::gtest_main)

# Para que los tests puedan incluir los headers y fuentes del proyecto
target_include_directories(runTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

include(GoogleTest)
gtest_discover_tests(runTests)
