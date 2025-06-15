cmake_minimum_required(VERSION 3.10)
project(VideoApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluir carpeta con headers
include_directories(${PROJECT_SOURCE_DIR})

# Archivos fuente
set(SOURCES
    main.cpp
    Video.cpp
    Pelicula.cpp
    Serie.cpp
    Episodio.cpp
)

# Ejecutable principal
add_executable(video_app ${SOURCES})

# GoogleTest
# Descargar e incluir automáticamente si no está instalado
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.13.0.zip
)
# Evitar usar install() en GTest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Ejecutable tests
add_executable(runTests
    test_episodio.cpp
    test_pelicula.cpp
    test_serie.cpp
    test_video.cpp
    Video.cpp
    Pelicula.cpp
    Serie.cpp
    Episodio.cpp
)

target_link_libraries(runTests gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)
