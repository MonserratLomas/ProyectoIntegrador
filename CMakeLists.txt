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

# Ejecutable principal
add_executable(ProyectoIntegrador ${SOURCE_FILES})

# --- GoogleTest setup ---
enable_testing()

# Buscar todos los archivos de test test_*.cpp en la carpeta test/
file(GLOB TEST_FILES "${CMAKE_SOURCE_DIR}/test/test_*.cpp")

message(STATUS "Archivos de test encontrados:")
foreach(f IN LISTS TEST_FILES)
  message(STATUS "  > ${f}")
endforeach()

# Archivo con el main de GoogleTest (test_main.cpp)
set(TEST_MAIN "${CMAKE_SOURCE_DIR}/test/test_main.cpp")

# Junta todos los archivos test, el main y los archivos fuente del proyecto
set(ALL_TEST_FILES ${TEST_MAIN} ${TEST_FILES} ${SOURCE_FILES})

# Busca GoogleTest en el sistema (requiere que esté instalado)
find_package(GTest REQUIRED)

# Define ejecutable para tests (ahora también compila las clases)
add_executable(runTests ${ALL_TEST_FILES})

# Link con GoogleTest y pthread (Linux/macOS)
target_link_libraries(runTests GTest::gtest_main pthread)

# Registra el test para ctest
add_test(NAME runTests COMMAND runTests)
