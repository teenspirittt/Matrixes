//
// Created by vladi on 17.11.2021.
//

#ifndef MATRIXES_SRC_IDENTITYMATRIX_H_
#define MATRIXES_SRC_IDENTITYMATRIX_H_

#include "Matrix.h"

class IdentityMatrix : public Matrix {
 public:
  IdentityMatrix();
  IdentityMatrix(const Matrix &copy);
  IdentityMatrix(unsigned int order);

};

#endif //MATRIXES_SRC_IDENTITYMATRIX_H_
