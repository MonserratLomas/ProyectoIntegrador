cmake_minimum_required(VERSION 3.14)
project(ProyectoIntegrador VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Opcional: activar opciones de cobertura si usas -DENABLE_COVERAGE=ON
option(ENABLE_COVERAGE "Enable code coverage" OFF)
if(ENABLE_COVERAGE)
  message(STATUS "Building with coverage enabled")
  add_compile_options(--coverage -O0)
  add_link_options(--coverage)
endif()

# --- Archivos fuente de la app principal ---
set(SOURCE_FILES
  main.cpp
  Video.cpp
  Pelicula.cpp
  Serie.cpp
  Episodio.cpp
)

add_executable(ProyectoIntegrador ${SOURCE_FILES})

# --- GoogleTest (FetchContent) ---
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.13.0.zip
)

# Evitar instalar GoogleTest durante build
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# --- Archivos tests ---
set(TEST_FILES
  test/EpisodioTest.cpp
  test/PeliculaTest.cpp
  test/SerieTest.cpp
  test/VideoTest.cpp
)

add_executable(runTests ${TEST_FILES})

target_link_libraries(runTests
  gtest_main
  gtest
  pthread
)

# Registrar tests para ctest
add_test(NAME runTests COMMAND runTests)
