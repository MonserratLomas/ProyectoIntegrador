cmake_minimum_required(VERSION 3.10)
project(RunTests)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)  # Si tienes headers aquí

# Archivos de test
set(TEST_FILES
    test_main.cpp
    test_episodio.cpp
    test_pelicula.cpp
    test_serie.cpp
    test_video.cpp
)

# Archivos de implementación que usan los tests (se refiere a la carpeta raíz con ../)
set(SOURCE_FILES
    ../Video.cpp
    ../Pelicula.cpp
    ../Serie.cpp
    ../Episodio.cpp
)

add_executable(runTests ${TEST_FILES} ${SOURCE_FILES})

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
