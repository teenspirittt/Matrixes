#include <cstring>
#include <iostream>
#include "../lib/IdentityMatrix.h"
#include "../lib/TriangularMatrix.h"
#include "../lib/Matrix.h"
#include "../lib/Node.h"
#include "../lib/UniLists.h"
#include "gtest/gtest.h"

TEST(lab1_tests, constructor_tests) {
  Matrix matrix(9, 9);
  Matrix cmp_matrix(9, 9);
  ASSERT_EQ(matrix.get_width(), 9);
  ASSERT_EQ(matrix.get_height(), 9);
  ASSERT_STREQ(matrix.get_matrix(), cmp_matrix.get_matrix());
  matrix.matrix_resize(5, 8);
  ASSERT_EQ(matrix.get_width(), 8);
  ASSERT_EQ(matrix.get_height(), 5);
}

TEST(lab1_tests, input_test) {
  Matrix matrix(9, 9);
  Matrix cmp_matrix(9, 9);

  matrix.set_matrix_from_file(1);
  cmp_matrix.set_matrix_from_file(1);;

  ASSERT_STREQ(matrix.get_matrix(), cmp_matrix.get_matrix());
}

TEST(lab1_tests, add_LC_test) {
  Matrix **matrix = nullptr;
  Matrix **cmp_matrix = nullptr;

  matrix = new Matrix *[1];
  cmp_matrix = new Matrix *[1];

  matrix[0] = new Matrix(9, 9);
  cmp_matrix[0] = new Matrix(9, 9);

  matrix[0]->set_matrix_from_file(1);
  cmp_matrix[0]->set_matrix_from_file(1);

  matrix[0]->add_line(reinterpret_cast<const int *>(matrix));
  cmp_matrix[0]->add_line(reinterpret_cast<const int *>(cmp_matrix));

  ASSERT_EQ(matrix[0]->get_height(), 10);
  ASSERT_EQ(cmp_matrix[0]->get_height(), 10);
  ASSERT_EQ(matrix[0]->get_width(), 9);
  ASSERT_EQ(cmp_matrix[0]->get_width(), 9);

  matrix[0]->add_column(reinterpret_cast<int *>(matrix));
  cmp_matrix[0]->add_column(reinterpret_cast<int *>(cmp_matrix));

  ASSERT_EQ(matrix[0]->get_width(), 10);
  ASSERT_EQ(cmp_matrix[0]->get_width(), 10);
  ASSERT_EQ(matrix[0]->get_height(), 10);
  ASSERT_EQ(cmp_matrix[0]->get_height(), 10);
}

TEST(lab1_tests, sort_LC_test) {
  Matrix matrix(9, 9);
  Matrix cmp_matrix(9, 9);

  matrix.set_matrix_from_file(1);
  cmp_matrix.set_matrix_from_file(1);

  matrix.sort_by_column(1);
  cmp_matrix.sort_by_column(1);

  ASSERT_EQ(matrix.get_height(), 9);
  ASSERT_EQ(cmp_matrix.get_height(), 9);
  ASSERT_EQ(matrix.get_width(), 9);
  ASSERT_EQ(cmp_matrix.get_width(), 9);
  ASSERT_STREQ(matrix.get_matrix(), cmp_matrix.get_matrix());

  matrix.sort_by_line(2);
  cmp_matrix.sort_by_line(2);

  ASSERT_EQ(matrix.get_height(), 9);
  ASSERT_EQ(cmp_matrix.get_height(), 9);
  ASSERT_EQ(matrix.get_width(), 9);
  ASSERT_EQ(cmp_matrix.get_width(), 9);
  ASSERT_STREQ(matrix.get_matrix(), cmp_matrix.get_matrix());
}

TEST(lab1_tests, find_test) {
  Matrix matrix(9, 9);

  matrix.set_matrix_from_file(1);

  ASSERT_EQ(matrix.get_num(1, 1), 143);
  ASSERT_EQ(matrix.get_num(3, 5), 139);
  ASSERT_EQ(matrix.get_num(6, 0), 37);
  ASSERT_EQ(matrix.get_num(23, 32), -1);
}

TEST(lab1_tests, coords_test) {
  Matrix matrix(9, 9);

  matrix.set_matrix_from_file(1);

  coords xy = matrix.get_coords(143);
  ASSERT_EQ(xy.x, 1);
  ASSERT_EQ(xy.y, 1);

  coords xy_1 = matrix.get_coords(139);
  ASSERT_EQ(xy_1.x, 3);
  ASSERT_EQ(xy_1.y, 5);

  coords xy_2 = matrix.get_coords(37);
  ASSERT_EQ(xy_2.x, 6);
  ASSERT_EQ(xy_2.y, 0);

  coords xy_3 = matrix.get_coords(251);
  ASSERT_EQ(xy_3.error, 1);
}

TEST(lab2_tests, exchange_test) {
  Matrix matrix1(9, 9);
  Matrix matrix2(9, 9);
  matrix1.set_matrix_from_file(1);
  matrix2.set_matrix_from_file(1);
  matrix1(1, 1, 4);
  matrix1(3, 4, 8);
  matrix1(4, 7, 99);
  ASSERT_EQ(matrix1.get_num(1, 1), 4);
  ASSERT_EQ(matrix1.get_num(3, 4), 8);
  ASSERT_EQ(matrix1.get_num(4, 7), 99);
}

TEST(lab2_tests, assignment_test) {
  Matrix matrix1(8, 8);
  Matrix matrix2;
  Matrix matrix3;
  matrix1.set_matrix_from_file(1);

  matrix3 = matrix2 = matrix1;
  ASSERT_STREQ(matrix1.get_matrix(), matrix2.get_matrix());
  ASSERT_STREQ(matrix1.get_matrix(), matrix3.get_matrix());
}

TEST(lab2_tests, indexing_test) {
  Matrix matrix1(8, 8);
  matrix1.set_matrix_from_file(1);

  ASSERT_EQ(matrix1[4][2], 126);
  ASSERT_EQ(matrix1[2][7], 26);
  ASSERT_EQ(matrix1[3][4], 206);
}

TEST(lab2_tests, addition_test) {
  Matrix matrix1(8, 8);
  Matrix matrix2(8, 8);
  Matrix matrix3;

  matrix1.set_matrix_from_file(1);
  matrix2.set_matrix_from_file(1);

  matrix3 = matrix1 + matrix2;

  matrix2.set_matrix_from_file(2);
  ASSERT_STREQ(matrix3.get_matrix(), matrix2.get_matrix());
}

TEST(lab2_tests, subtraction_test) {
  Matrix matrix1(8, 8);
  Matrix matrix2(8, 8);
  Matrix matrix3;

  matrix1.set_matrix_from_file(1);
  matrix2.set_matrix_from_file(1);

  matrix3 = matrix1 - matrix2;
  matrix2.set_matrix_from_file(3);
  ASSERT_STREQ(matrix3.get_matrix(), matrix2.get_matrix());
}

TEST(lab3_tests, stream_test) {
  Matrix m1(8, 8);
  m1.set_matrix_from_file(1);
  Matrix m2(8, 8);
  m2.set_matrix_from_file(1);
  Matrix m3(8, 8);
  ofstream out;
  out.open("../src/materials/Matrix.txt");
  if (!out.is_open()) {
    std::cerr << "fileOut open failed: " << std::strerror(errno) << "\n";
    ASSERT_TRUE(0);
  }
  out << m1 << std::endl;
  out << m2 << std::endl;
  out.close();

  ifstream in("../src/materials/Matrix.txt");
  if (!in.is_open()) {
    std::cerr << "fileOut open failed: " << std::strerror(errno) << "\n";
    ASSERT_TRUE(0);
  }
  in >> m3;
  ASSERT_STREQ(m1.get_matrix(), m3.get_matrix());
  in >> m3;
  ASSERT_STREQ(m1.get_matrix(), m3.get_matrix());
  in.close();

  ofstream b_in("../src/materials/matrix.dat", ios::binary);
  if (!b_in.is_open()) {
    std::cerr << "b_in open failed: " << std::strerror(errno) << "\n";
    ASSERT_TRUE(0);
  }
  b_in << m1 << std::endl;
  b_in << m2 << std::endl;
  b_in.close();

  ifstream b_out("../src/materials/matrix.dat", ios::binary);
  if (!b_out.is_open()) {
    std::cerr << "b_out open failed: " << std::strerror(errno) << "\n";
    ASSERT_TRUE(0);
  }
  b_out >> m3;
  ASSERT_STREQ(m1.get_matrix(), m3.get_matrix());
  b_out >> m3;
  ASSERT_STREQ(m2.get_matrix(), m3.get_matrix());
  b_out.close();
}

TEST(lab4_tests, IdentityMatrix) {
  IdentityMatrix q(3);
  ASSERT_STREQ(q.get_matrix(), "1 0 0 \n0 1 0 \n0 0 1 \n");
  IdentityMatrix w(5);
  ASSERT_STREQ(w.get_matrix(), "1 0 0 0 0 \n0 1 0 0 0 \n0 0 1 0 0 \n0 0 0 1 0 \n0 0 0 0 1 \n");
  Matrix r;
  r = w + w;
  ASSERT_STREQ(r.get_matrix(), "2 0 0 0 0 \n0 2 0 0 0 \n0 0 2 0 0 \n0 0 0 2 0 \n0 0 0 0 2 \n");
}

TEST(lab4_tests, TriangularMatrix) {
  TriangularMatrix q(3);
  ASSERT_STREQ(q.get_matrix(), "1 1 1 \n0 1 1 \n0 0 1 \n");
  TriangularMatrix w(5);
  ASSERT_STREQ(w.get_matrix(), "1 1 1 1 1 \n0 1 1 1 1 \n0 0 1 1 1 \n0 0 0 1 1 \n0 0 0 0 1 \n");
}

TEST(lab5_tests, polymorf) {
  List lst;
  Matrix M(3, 3);
  TriangularMatrix T(3);
  IdentityMatrix I(3);
  Matrix io(7, 7);
  TriangularMatrix TR(2);
  IdentityMatrix IM(9);
  IM.set_matrix_from_file(1);
  ASSERT_EQ(lst.count(), 0);
  lst.add(&T);
  ASSERT_EQ(lst.count(), 1);
  lst.add(&M);
  ASSERT_EQ(lst.count(), 2);
  lst.add(&I);
  ASSERT_EQ(lst.count(), 3);
  lst.add(&io);
  ASSERT_EQ(lst.count(), 4);
  lst.del();
  ASSERT_EQ(lst.count(), 3);
  lst.add(&io);
  ASSERT_EQ(lst.count(), 4);
  lst.del();
  lst.del();
  ASSERT_EQ(lst.count(), 2);
  lst.del();
  lst.add(&T);
  lst.del();
  ASSERT_EQ(lst.count(), 1);
  lst.add(&M);
  lst.add(&T);
  ASSERT_EQ(lst.count(), 3);
  lst.add(&I);
  ASSERT_EQ(lst.count(), 4);
  lst.add(&io);
  ASSERT_EQ(lst.count(), 5);
  ASSERT_STREQ(lst[0].get_matrix(), T.get_matrix());
  ASSERT_STREQ(lst[1].get_matrix(), M.get_matrix());
  ASSERT_STREQ(lst[2].get_matrix(), T.get_matrix());
  ASSERT_STREQ(lst[3].get_matrix(), I.get_matrix());
  ASSERT_STREQ(lst[4].get_matrix(), io.get_matrix());
  lst.del(2);
  ASSERT_EQ(lst.count(), 4);
  ASSERT_STREQ(lst[0].get_matrix(), T.get_matrix());
  ASSERT_STREQ(lst[1].get_matrix(), M.get_matrix());
  ASSERT_STREQ(lst[2].get_matrix(), I.get_matrix());
  ASSERT_STREQ(lst[3].get_matrix(), io.get_matrix());
  lst.del(3);
  ASSERT_EQ(lst.count(), 3);
  ASSERT_STREQ(lst[0].get_matrix(), T.get_matrix());
  ASSERT_STREQ(lst[1].get_matrix(), M.get_matrix());
  ASSERT_STREQ(lst[2].get_matrix(), I.get_matrix());
  lst.add(&TR,1);
  ASSERT_EQ(lst.count(), 4);
  ASSERT_STREQ(lst[0].get_matrix(), T.get_matrix());
  ASSERT_STREQ(lst[1].get_matrix(), TR.get_matrix());
  ASSERT_STREQ(lst[2].get_matrix(), M.get_matrix());
  ASSERT_STREQ(lst[3].get_matrix(), I.get_matrix());
  lst.add(&IM,3);
  ASSERT_EQ(lst.count(), 5);
  ASSERT_STREQ(lst[0].get_matrix(), T.get_matrix());
  ASSERT_STREQ(lst[1].get_matrix(), TR.get_matrix());
  ASSERT_STREQ(lst[2].get_matrix(), M.get_matrix());
  ASSERT_STREQ(lst[3].get_matrix(), IM.get_matrix());
  ASSERT_STREQ(lst[4].get_matrix(), I.get_matrix());
}

TEST(lab7_tests, templates) {
  UniversalList<int> lst;
  int n1 = 1;
  int n2 = 2;
  int *num1 = &n1;
  int *num2 = &n2;
  lst.add(num1);
  lst.add(num2);
  std::cout << lst[0];
  std::cout << lst[1];
}