cmake_minimum_required(VERSION 3.14)
project(ProyectoIntegrador VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_COVERAGE "Enable code coverage" OFF)
if(ENABLE_COVERAGE)
  message(STATUS "Building with coverage enabled")
  add_compile_options(--coverage -O0)
  add_link_options(--coverage)
endif()

# Archivos fuente principales
set(SOURCE_FILES
  main.cpp
  Video.cpp
  Pelicula.cpp
  Serie.cpp
  Episodio.cpp
)

add_executable(ProyectoIntegrador ${SOURCE_FILES})

# --- GoogleTest setup ---
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.13.0.zip
)

# For Windows: Force shared CRT
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Buscar todos los archivos de test test_*.cpp en la carpeta test/
file(GLOB TEST_FILES "${CMAKE_SOURCE_DIR}/test/test_*.cpp")

message(STATUS "Archivos de test encontrados:")
foreach(f IN LISTS TEST_FILES)
  message(STATUS "  > ${f}")
endforeach()

# Archivo con el main de GoogleTest (test_main.cpp)
set(TEST_MAIN "${CMAKE_SOURCE_DIR}/test/test_main.cpp")

# Junta todos los archivos test y el main
set(ALL_TEST_FILES ${TEST_MAIN} ${TEST_FILES})${SOURCE_FILES})

# Define ejecutable para tests
add_executable(runTests ${ALL_TEST_FILES})

# Link con GoogleTest y pthread (Linux/macOS)
target_link_libraries(runTests gtest_main pthread)

# Registra el test para ctest
add_test(NAME runTests COMMAND runTests)
