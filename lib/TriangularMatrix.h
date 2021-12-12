#ifndef MATRIXES_SRC_TRIANGULARMATRIX_H_
#define MATRIXES_SRC_TRIANGULARMATRIX_H_

#include "Matrix.h"

class TriangularMatrix : public Matrix {

public:
	TriangularMatrix();
	TriangularMatrix(const TriangularMatrix& copy);
	char* get_matrix() override;
	explicit TriangularMatrix(int order);
	void operator()(unsigned int i, unsigned int j, int val);
	int* operator[](int a) override;
	~TriangularMatrix();
private:
	int* nums;
};

#endif //MATRIXES_SRC_TRIANGULARMATRIX_H_
