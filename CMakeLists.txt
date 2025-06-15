cmake_minimum_required(VERSION 3.30)

project(ProyectoIntegrador VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Carpeta raíz donde están los headers
# Esto es mejor que include_directories, usa target_include_directories

set(SOURCES
        main.cpp
        Video.cpp
        Pelicula.cpp
        Serie.cpp
        Episodio.cpp
)

add_executable(ProyectoIntegrador ${SOURCES})

# Indica dónde están los headers para este target
target_include_directories(ProyectoIntegrador PRIVATE ${CMAKE_SOURCE_DIR})
