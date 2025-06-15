# CMakeLists.txt dentro de la carpeta de test

cmake_minimum_required(VERSION 3.10)
project(RunTests)

# Busca GTest y crea un target para los tests
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Archivos de prueba, excluye main.cpp
set(TEST_FILES
    test/test_episodio.cpp
    test/test_main.cpp  # Si quieres, puedes mantener test_main.cpp si se encarga de inicializar y ejecutar los tests
    test/test_pelicula.cpp
    test/test_serie.cpp
    test/test_video.cpp
)

# Crea el ejecutable de los tests sin incluir main.cpp del proyecto principal
add_executable(runTests ${TEST_FILES})

# Enlaza con GTest
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
