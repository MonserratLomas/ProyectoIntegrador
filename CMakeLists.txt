# Habilitar testing
enable_testing()

# Descargar e incluir GoogleTest si no está disponible
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Fuentes de tests
set(TEST_SOURCES
    test/test_episodio.cpp
    test/test_pelicula.cpp
    test/test_serie.cpp
    test/test_video.cpp
)

# Crear ejecutable de tests
add_executable(tests ${TEST_SOURCES})

# Linkear con GoogleTest y pthread (necesario en Linux/macOS)
target_link_libraries(tests gtest_main pthread)

# Incluir directorio raíz para que encuentre headers
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR})

# Registrar el test para ctest
add_test(NAME all_tests COMMAND tests)
