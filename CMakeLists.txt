cmake_minimum_required(VERSION 3.10)

project(ProyectoIntegrador VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Archivos fuente del proyecto principal
set(SOURCES
    main.cpp
    Video.cpp
    Pelicula.cpp
    Serie.cpp
    Episodio.cpp
)

# Crear el ejecutable principal
add_executable(ProyectoIntegrador ${SOURCES})
target_include_directories(ProyectoIntegrador PRIVATE ${CMAKE_SOURCE_DIR})

# --- Setup GoogleTest --- #

# Descargar GoogleTest si no está (requiere CMake >= 3.11)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Evitar instalación propia de gtest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Archivos fuente de tests
set(TEST_SOURCES
    test/test_video.cpp
    test/test_pelicula.cpp
    test/test_serie.cpp
    test/test_episodio.cpp
)

# Crear ejecutable de tests
add_executable(runTests ${TEST_SOURCES})

# Incluir headers
target_include_directories(runTests PRIVATE ${CMAKE_SOURCE_DIR})

# Linkear con GoogleTest y pthread
target_link_libraries(runTests gtest_main)

# Registrar tests automáticamente para ctest
include(GoogleTest)
gtest_discover_tests(runTests)
