cmake_minimum_required(VERSION 3.10)
project(ProyectoIntegrador)

# Configuración para el estándar C++ y cobertura
set(CMAKE_CXX_STANDARD 14)

# Flags para cobertura de código
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

# Especificar los archivos fuente principales
add_executable(ProyectoIntegrador
    main.cpp
    Video.cpp
    Pelicula.cpp
    Serie.cpp
    Episodio.cpp
)

# Añadir directorios de cabeceras (si tienes alguno)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Configuración para tests
enable_testing()
add_subdirectory(test)

# Encontrar GoogleTest para el ejecutable principal (si es que usas GTest con el main, normalmente no es necesario)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(ProyectoIntegrador ${GTEST_LIBRARIES})
