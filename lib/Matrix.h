#ifndef MATRIXES__MATRIX_H_
#define MATRIXES__MATRIX_H_

#include <fstream>
#include <istream>
#include <ostream>
using namespace std;

struct coords {
  int x, y, error;
  coords() {
    x = 0;
    y = 0;
    error = 0;
  }
  coords(int n) {
    x = 0;
    y = 0;
    error = n;
  }
  coords(int x, int y) {
    this->x = x;
    this->y = y;
    error = 0;
  }
};

class Matrix {
 public:
  Matrix();
  Matrix(int height, int width);
  Matrix(const Matrix &copy);
  ~Matrix();

  void matrix_resize(int height, int width);
  void add_column(int *a);
  void add_line(const int *a);
  char *get_matrix();
  int get_num(int x, int y);
  int get_height() const;
  int get_width() const;
  void randomize_matrix(int range);
  int set_matrix_from_file(int file);
  void sort_by_line(int n);
  void sort_by_column(int n);
  int *operator[](int a);
  Matrix &operator=(const Matrix &a);
  Matrix operator+(Matrix &a);
  Matrix operator-(Matrix &a);
  void operator()(int x, int y, int val);
  struct coords get_coords(int digit);
  friend istream &operator>>(istream &stream, Matrix &matrix);
  friend ostream &operator<<(ostream &stream, Matrix &matrix);
  ofstream &to_bin(ofstream &out);
  ifstream &from_bin(ifstream &in);
  Matrix mul(Matrix &a, Matrix &b);
  Matrix mul(Matrix &a, int num);
 protected:
  int lines, columns;
  int **num;
  static void add_digit(char *str, int *cnt, int digit);
  static int get_num_length(int num);

};

#endif //MATRIXES__MATRIX_H_
