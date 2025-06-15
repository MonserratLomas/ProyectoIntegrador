#cmake_minimum_required(VERSION 3.10)
project(RunTests)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(TEST_FILES
    test_main.cpp
    test_episodio.cpp
    test_pelicula.cpp
    test_serie.cpp
    test_video.cpp
)

# Importante: incluir también los archivos fuente necesarios para testear,
# pero NO main.cpp del proyecto principal
add_executable(runTests
    ${TEST_FILES}
    ../Video.cpp
    ../Pelicula.cpp
    ../Serie.cpp
    ../Episodio.cpp
)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
