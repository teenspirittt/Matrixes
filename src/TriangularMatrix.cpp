#include "../lib/TriangularMatrix.h"

TriangularMatrix::TriangularMatrix() {
  lines = 0;
  columns = 0;
  nums = nullptr;
}
TriangularMatrix::TriangularMatrix(int order) {
  lines = order;
  columns = order;
  int step = 0;
  nums = new int(columns);
  for (int i = 0; i < lines * columns; ++i) {
    nums[i] = 0;
  }
  for (int i = 0; i < lines; ++i) {
    for (int j = step; j < columns; ++j) {
      nums[i * columns + j] = 1;
    }
    step++;
  }
}
int TriangularMatrix::operator[](int a) {
  return nums[a];
}

//TriangularMatrix::TriangularMatrix(const Matrix &a) {
//  unsigned int i, j, k;
//  int count_swaps = 1;
//  Matrix c = a;
//  for (i = 0; i < a.lines; ++i) {
//    // находим строку с максимальным первым элементом
//    int iMax = i;
//    for (j = i + 1; j < a.lines; ++j)
//      if (abs(c[j][i]) > abs(c[iMax][i]))
//        iMax = j;
//    if (abs(c[iMax][i]) < eps)
//      continue;
//    for (k = 0; k < a.columns; ++k)
//      swap(c[i][k], c[iMax][k]);
//    count_swaps = -count_swaps * (i != iMax ? 1 : -1);
//
//    //  вычитаем текущую строку из всех остальных
//    for (j = i + 1; j < a.columns; ++j) {
//      double q = -c[j][i] / c[i][i];
//      for (k = a.columns - 1; k >= i; --k)
//        c[j][k] += q * c[i][k];
//    }
//  }
//  // умножаем матрицу на -1, если мы сделали  нечётное количество перестановок строк
//  // в итоге определитель результирующей матрицы  будет равен определителю начальной матрицы
//  mul(c, count_swaps);
//}


