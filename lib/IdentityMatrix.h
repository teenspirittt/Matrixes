#ifndef MATRIXES_SRC_IDENTITYMATRIX_H_
#define MATRIXES_SRC_IDENTITYMATRIX_H_

#include "Matrix.h"

class IdentityMatrix : public Matrix {
 public:
  IdentityMatrix();
  explicit IdentityMatrix(const Matrix &copy);
  explicit IdentityMatrix(unsigned int order);
  ~IdentityMatrix() {};
};

#endif //MATRIXES_SRC_IDENTITYMATRIX_H_
