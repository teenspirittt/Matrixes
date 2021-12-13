#include "../lib/Matrix.h"
#include <exception>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

Matrix::Matrix() {
  columns = 0;
  lines = 0;
  num = nullptr;
}

Matrix::Matrix(int height, int width) {
  if (height <= 0 || width <= 0) {
    throw invalid_argument("Invalid argument");
  }
  lines = height;
  columns = width;
  num = new int *[columns];
  for (int i = 0; i < columns; ++i) {
    num[i] = new int[lines];
    for (int j = 0; j < lines; ++j) {
      num[i][j] = 0;
    }
  }
}

Matrix::Matrix(const Matrix &copy) {
  lines = copy.lines;
  columns = copy.columns;
  num = new int *[copy.columns];
  for (int i = 0; i < copy.columns; ++i) {
    num[i] = new int[copy.lines];
    for (int j = 0; j < copy.lines; ++j) {
      num[i][j] = 0;
    }
  }
}

Matrix::~Matrix() {
  if (num != nullptr) {
    while (columns--) {
      delete[]num[columns];
    }
    delete[]num;
  }
}

void Matrix::add_column(int *a) {
  int **tmp = num;
  columns++;
  num = new int *[columns];
  int i;
  for (i = 0; i < columns; ++i) {
    num[i] = tmp[i];
  }
  delete[]tmp;
  num[i] = a;
}

void Matrix::add_line(const int *a) {
  int **tmp = num;
  num = new int *[columns];
  int i, j;
  lines++;
  for (i = 0; i < columns; ++i) {
    num[i] = new int[lines];
    for (j = 0; j < lines - 1; ++j) {
      num[i][j] = tmp[i][j];
    }
    delete[]tmp[i];
    num[i][j] = a[i];
  }
  delete[]tmp;
}

void Matrix::sort_by_column(int n) {
  if (n < 0) {
    throw invalid_argument("Invalid argument");
  }
  for (int i = 0; i < lines; ++i) {
    int min = i;
    for (int j = i + 1; j < lines; ++j) {
      if (num[n][j] < num[n][min]) {
        min = j;
      }
    }
    for (int k = 0; k < columns; ++k) {
      int tmp = num[k][i];
      num[k][i] = num[k][min];
      num[k][min] = tmp;
    }
  }
}

void Matrix::sort_by_line(int n) {
  if (n < 0) {
    throw invalid_argument("Invalid argument");
  }
  n++;
  for (int i = 0; i < columns; ++i) {
    int min = i;
    for (int j = i + 1; j < columns; ++j) {
      if (num[j][n] < num[min][n]) {
        min = j;
      }
    }
    for (int k = 0; k < lines; ++k) {
      int tmp = num[i][k];
      num[i][k] = num[min][k];
      num[min][k] = tmp;
    }
  }
}

char *Matrix::get_matrix() {
  int i, j;
  int max[columns + 1];
  for (i = 0; i < columns; ++i) {
    max[i] = 0;
    for (j = 0; j < lines; ++j) {
      int t;
      if ((t = get_num_length(num[i][j])) > max[i]) {
        max[i] = t;
      }
    }
  }
  max[columns] = 0;
  for (i = 0; i < columns; ++i) {
    max[columns] += max[i] + 1;
  }
  int cnt = 0;
  char *res = new char[(max[columns] + columns) * lines + 1];
  for (i = 0; i < lines; ++i) {
    for (j = 0; j < columns; ++j) {
      add_digit(res, &cnt, num[j][i]);
      for (int m = 0; m < max[j] - get_num_length(num[j][i]); ++m) {
        res[cnt++] = ' ';
      }
      res[cnt++] = ' ';
    }
    res[cnt++] = '\n';
  }
  res[cnt++] = '\0';

  return res;
}

void Matrix::add_digit(char *str, int *cnt, int digit) {
  int tmp = *cnt;
  if (digit == 0) {
    str[(*cnt)++] = '0';
    return;
  }

  int length = get_num_length(digit);
  tmp += length;
  if (digit < 0) {
    str[(*cnt++)] = '-';
    length--;
  }
  digit = fabs(digit);
  while (digit) {
    str[*cnt + length - 1] = static_cast<char>((digit % 10) + '0');
    digit /= 10;
    length--;
  }
  *cnt = tmp;
}

int Matrix::get_num_length(int num) {
  int res = 0;
  if (num == 0) {
    return 1;
  }
  if (num < 0) {
    res++;
    num = fabs(num);
  }
  while (num) {
    num /= 10;
    res++;
  }
  return res;
}

struct coords Matrix::get_coords(int digit) {
  for (int i = 0; i < lines; ++i) {
    for (int j = 0; j < columns; ++j) {
      if (num[j][i] == digit) {
        return {j, i};
      }
    }
  }
  return {1};
}

void Matrix::matrix_resize(int height, int width) {
  if (height < 0 || width < 0) {
    throw invalid_argument("Invalid argument");
  }
  int **tmp = num;
  num = new int *[width];

  for (int i = 0; i < width; ++i) {
    num[i] = new int[height];

    for (int j = 0; j < height; ++j) {
      if (i < columns && j < lines)
        num[i][j] = tmp[i][j];
      else
        num[i][j] = 0;

    }
    if (i < columns)
      delete[]tmp[i];
  }
  delete[]tmp;
  lines = height;
  columns = width;
}

void Matrix::randomize_matrix(int range) {
  if (range < 0) {
    throw invalid_argument("Invalid argument");
  }
  for (int i = 0; i < columns; ++i) {
    for (int j = 0; j < lines; ++j) {
      num[i][j] = rand() % range;
    }
  }
}

int Matrix::set_matrix_from_file(int file) {
  std::ifstream f;
  if (file == 1)
    f.open("C:\\Users\\vladi\\CLionProjects\\Matrixes\\src\\materials\\NumbersForMatrix.txt");
  else if (file == 2)
    f.open("C:\\Users\\vladi\\CLionProjects\\Matrixes\\src\\materials\\add_tst.txt");
  else if (file == 3)
    f.open("C:\\Users\\vladi\\CLionProjects\\Matrixes\\src\\materials\\subt_tst.txt");
  if (!f) {
    return 1;
  }
  for (int i = 0; i < columns; ++i) {
    for (int j = 0; j < lines; ++j) {
      f >> num[i][j];

    }
  }
  f.close();
  return 0;
}

int *Matrix::operator[](int a) {
  return num[a];
}

Matrix &Matrix::operator=(const Matrix &a) {
  if (num != nullptr) {
    while (columns--) {
      delete[]num[columns];
    }
    delete[]num;
  }
  columns = a.columns;
  lines = a.lines;
  num = new int *[columns];
  for (int i = 0; i < a.columns; ++i) {
    num[i] = new int[a.lines];
    for (int j = 0; j < lines; ++j) {
      num[i][j] = a.num[i][j];
    }
  }
  return *this;
}

Matrix Matrix::operator+(Matrix &a) {
  Matrix result = Matrix(std::max(columns, a.columns),
                         std::max(lines, a.lines));
  for (int i = 0; i < (std::max(columns, a.columns)); ++i) {
    for (int j = 0; j < (std::max(lines, a.lines)); ++j) {
      if (i < columns && i < a.columns && j < lines && j < a.lines) {
        result[i][j] = num[i][j] + a[i][j];
      } else if (i < columns && j < lines) {
        result[i][j] = num[i][j];
      } else if (i < a.columns && j < a.lines) {
        result[i][j] = a[i][j];
      } else {
        result[i][j] = 0;
      }
    }
  }
  return result;
}

Matrix Matrix::operator-(Matrix &a) {
  Matrix result = Matrix(std::max(columns, a.columns),
                         std::max(lines, a.lines));
  for (int i = 0; i < (std::max(columns, a.columns)); ++i) {
    for (int j = 0; j < (std::max(lines, a.lines)); ++j) {
      if (i < columns && i < a.columns && j < lines && j < a.lines) {
        result[i][j] = num[i][j] - a[i][j];
      } else if (i < columns && j < lines) {
        result[i][j] = num[i][j];
      } else if (i < a.columns && j < a.lines) {
        result[i][j] = -a[i][j];
      } else {
        result[i][j] = 0;
      }
    }
  }
  return result;
}

ostream &operator<<(ostream &stream, Matrix &matrix) {
  stream << matrix.get_matrix() << std::endl;
  return stream;
}

istream &operator>>(istream &stream, Matrix &matrix) {
  for (int i = 0; i < matrix.lines; ++i) {
    for (int j = 0; j < matrix.columns; ++j) {
      stream >> matrix[j][i];
    }
  }
  return stream;
}

ofstream &Matrix::to_bin(ofstream &out) {
  int *ptr = new int(this->get_width());
  out.write(reinterpret_cast<const char *>(ptr), sizeof(this->get_width()));
  *ptr = this->get_height();
  out.write(reinterpret_cast<const char *>(ptr), sizeof(this->get_height()));

  for (int i = 0; i < this->get_width(); ++i)
    for (int j = 0; j < this->get_height(); ++j)
      out.write(reinterpret_cast<const char *>((*this)[i][j]), sizeof((*this)[i][j]));
  return out;
}

ifstream &Matrix::from_bin(ifstream &in) {
  char Bin[] = "Bin";
  int i, j;
  char c;
  for (i = 0; i < 3; ++i) {
    in.get(c);
    if (Bin[i] != c)
      return in;  //error
  }
  int *ptr = new int;
  in.read(reinterpret_cast<char *>(ptr), sizeof(this->get_width()));
  i = *ptr;
  in.read(reinterpret_cast<char *>(ptr), sizeof(this->get_height()));
  j = *ptr;
  this->matrix_resize(i, j);
  for (i = 0; i < this->get_width(); ++i)
    for (j = 0; j < this->get_height(); ++j)
      in.read(reinterpret_cast<char *>((*this)[i][j]), sizeof((*this)[i][j]));
  return in;
}

void Matrix::operator()(int x, int y, int val) {
  num[x][y] = val;
}

int Matrix::get_num(int x, int y) {
  if (x < 0 || y < 0) {
    throw invalid_argument("Invalid argument");
  }
  if ((x > lines) || (y > columns)) {
    return -1;
  }
  return num[x][y];
}

int Matrix::get_height() const {
  return lines;
}

int Matrix::get_width() const {
  return columns;
}

Matrix Matrix::mul(Matrix &a, Matrix &b) {
  if (a.lines != b.columns)
    return Matrix();
  Matrix c = Matrix(a.lines, b.columns);
  for (int i = 0; i < a.lines; ++i)
    for (int j = 0; j < b.columns; ++j)
      for (int k = 0; k < a.columns; ++k)
        c[i][j] += a[i][k] * b[k][j];
  return c;
}

Matrix Matrix::mul(Matrix &a, int num) {
  Matrix c = Matrix(a.lines, a.columns);
  for (int i = 0; i < a.lines; ++i)
    for (int j = 0; j < a.columns; ++j)
      c[i][j] = a[i][j] * num;
  return c;
}

bool operator>(const Matrix &a, const Matrix &b) {
  int sum1 = 0;
  for (int i = 0; i < a.lines; ++i) {
    for (int j = 0; j < a.columns; ++j) sum1 = a[i][j]++;
  }
  int sum2 = 0;
  for (int i = 0; i < b.lines; ++i) {
    for (int j = 0; j < b.columns; ++j) {
      sum2 = b[i][j]++;
    }
  }
  if (sum1 > sum2) {
    return true;
  } else {
    return false;
  }
}

bool operator<(const Matrix &a, const Matrix &b) {
  int sum1 = 0;
  for (int i = 0; i < a.lines; ++i) {
    for (int j = 0; j < a.columns; ++j) {
      sum1 = a[i][j]++;
    }
  }
  int sum2 = 0;
  for (int i = 0; i < b.lines; ++i) {
    for (int j = 0; j < b.columns; ++j) {
      sum2 = b[i][j]++;
    }
  }
  if (sum1 < sum2) {
    return true;
  } else {
    return false;
  }
}

bool operator==(Matrix &a, Matrix &b) {
  if (a.lines != b.lines || a.columns != b.columns)
    return false;
  for (int i = 0; i < b.lines; ++i) {
    for (int j = 0; j < b.columns; ++j) {
      if (b[i][j] != a[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool operator!=(Matrix &a, Matrix &b) {
  if (a.lines != b.lines || a.columns != b.columns)
    return false;
  for (int i = 0; i < b.lines; ++i) {
    for (int j = 0; j < b.columns; ++j) {
      if (b[i][j] != a[i][j]) {
        return true;
      }
    }
  }
  return false;
}
int *Matrix::operator[](int a) const {
  return num[a];
}

