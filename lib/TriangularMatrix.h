//
// Created by vladi on 17.11.2021.
//

#ifndef MATRIXES_SRC_TRIANGULARMATRIX_H_
#define MATRIXES_SRC_TRIANGULARMATRIX_H_

#include "Matrix.h"

class TriangularMatrix : public Matrix {
 private:
  int *nums;
 public:
  TriangularMatrix();
  TriangularMatrix(const TriangularMatrix &);
  char *get_matrix() override;
  explicit TriangularMatrix(int order);
  void operator()(unsigned int i, unsigned int j, int val);
  int *operator[](int a) override;
  ~TriangularMatrix();
};

#endif //MATRIXES_SRC_TRIANGULARMATRIX_H_
