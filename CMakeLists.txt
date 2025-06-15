cmake_minimum_required(VERSION 3.10)
project(ProyectoIntegrador)

# Usar C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Habilitar flags de cobertura (funciona con gcc y clang)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -O0 -g")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

# Archivos fuente principales
set(SOURCES
    main.cpp
    Video.cpp
    Pelicula.cpp
    Serie.cpp
    Episodio.cpp
)

add_executable(ProyectoIntegrador ${SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/include)

# GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link GTest a tu ejecutable (opcional si no usas en main)
target_link_libraries(ProyectoIntegrador ${GTEST_LIBRARIES} pthread)

# Habilitar tests
enable_testing()

# Tests: agregar subdirectorio test
add_subdirectory(test)
