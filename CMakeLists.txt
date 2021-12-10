cmake_minimum_required(VERSION 3.14)
project(Matrixes)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(Google_tst)
add_executable(Matrixes src/main.cpp lib/Matrix.h src/Matrix.cpp Google_tst/test_matrixes.cpp src/TriangularMatrix.cpp lib/TriangularMatrix.h src/IdentityMatrix.cpp lib/IdentityMatrix.h src/Node.cpp lib/Node.h src/UniversalNode.cpp lib/UniversalNode.h)
target_link_libraries(Matrixes gtest gtest_main )