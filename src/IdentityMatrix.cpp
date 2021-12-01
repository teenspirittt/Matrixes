#include "../lib/IdentityMatrix.h"

IdentityMatrix::IdentityMatrix() : Matrix() {}

IdentityMatrix::IdentityMatrix(const Matrix &copy) : Matrix(copy) {}

IdentityMatrix::IdentityMatrix(unsigned int order) {
  lines = order;
  columns = order;
  num = new int *[columns];
  for (int i = 0; i < columns; ++i) {
    num[i] = new int[lines];
    for (int j = 0; j < lines; ++j) {
      num[i][j] = 0;
    }
  }
  for (int i = 0; i < lines; ++i) {
    num[i][i] = 1;
  }
}