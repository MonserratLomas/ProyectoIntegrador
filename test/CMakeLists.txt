cmake_minimum_required(VERSION 3.10)
project(RunTests)

# Flags para cobertura de código (también aquí)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

# Encontrar GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Archivos de test (no incluir main.cpp del proyecto principal para evitar conflictos)
set(TEST_FILES
    test_episodio.cpp
    test_main.cpp   # este es el main solo para test
    test_pelicula.cpp
    test_serie.cpp
    test_video.cpp
)

# Crear ejecutable para tests
add_executable(runTests ${TEST_FILES})

# Linkear con GoogleTest y pthread (necesario en Linux/mac)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
