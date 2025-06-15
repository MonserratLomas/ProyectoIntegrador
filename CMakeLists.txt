cmake_minimum_required(VERSION 3.10)
project(ProyectoIntegrador)

set(CMAKE_CXX_STANDARD 14)

# Ejecutable principal SIN GTest (no lo necesita)
add_executable(ProyectoIntegrador main.cpp Video.cpp Pelicula.cpp Serie.cpp Episodio.cpp)

# Incluye carpeta de headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Solo habilitar testing y agregar subdirectorio test, no linkear GTest aquí
enable_testing()
add_subdirectory(test)
