cmake_minimum_required(VERSION 3.10)
project(ProyectoIntegrador)

# Configuración para el estándar C++ y el compilador
set(CMAKE_CXX_STANDARD 14)

# Especificar los archivos fuente principales
add_executable(ProyectoIntegrador main.cpp Video.cpp Pelicula.cpp Serie.cpp Episodio.cpp)

# Añadir directorios de cabeceras (si tienes alguno)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Configuración de los tests usando Google Test
enable_testing()
add_subdirectory(test)

# Si tienes alguna biblioteca de terceros, como GTest, añádela
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(ProyectoIntegrador ${GTEST_LIBRARIES})
