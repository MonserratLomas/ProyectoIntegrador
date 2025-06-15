# Añadir el ejecutable para los tests
add_executable(runTests 
    test_episodio.cpp
    test_main.cpp
    test_pelicula.cpp
    test_serie.cpp
    test_video.cpp
)

# Vincular la librería de Google Test
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Añadir pruebas
add_test(NAME runTests COMMAND runTests)
