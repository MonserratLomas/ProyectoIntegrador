# test/CMakeLists.txt

# Busca todos los archivos test_*.cpp
file(GLOB TEST_FILES "test_*.cpp")

# Crea el ejecutable de tests
add_executable(runTests test_main.cpp ${TEST_FILES})

# Enlaza GoogleTest
target_link_libraries(runTests gtest_main pthread)

# Registra los tests
add_test(NAME runTests COMMAND runTests)
