#include "Matrix.h"

std::ostream& operator<< (std::ostream& os, const Matrix & matrix) {

    // for (int row = 0; row < matrix._data.size(); row++) {
    //     for (int col = 0; row < matrix._data[row].size(); col++)
    //         os << matrix._data[row][col] << ' ';
    //     os << std::endl;
    // }

    for (auto row : matrix._data) {
        for (auto cell : row)
            os << cell << ' ';
        os << std::endl;
    }
    return os;
}

Matrix &Matrix::operator=(const std::vector<std::vector<int> > &data) {
    this->_data = data;
    return *this;
}

static void applyOperation(std::vector<std::vector<int> > &a,
                           const std::vector<std::vector<int> > &b, int (*f)(int a, int b)) {

    size_t size = b.size();

    for (size_t row = 0; row < size; row++)
        for (size_t col = 0; col < size; col++)
            a[row][col] = f(a[row][col], b[row][col]);
}

int add(int a, int b) { return a+b; }
int sub(int a, int b) { return a-b; }
int mul(int a, int b) { return a*b; }
int divide(int a, int b) { return b == 0 ? 0 : a/b; }

Matrix &Matrix::operator+=(const Matrix &other) {
    // if (this->_data.size() <= other._data.size()) {
    //     for (int row = 0; row < this->_data.size(); row++) {
    //         for (int col = 0; row < this->_data[row].size(); col++) {
    //             this->_data[row][col] += other._data[row][col];
    //         }
    //     }
    // }
    // else {
    //     for (int row = 0; row < other._data.size(); row++) {
    //         for (int col = 0; row < other._data[row].size(); col++) {
    //             this->_data[row][col] += other._data[row][col];
    //         }
    //     }
    // }
    // return *this;
    applyOperation(_data, other._data, add);
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &other) {
    // std::cout << '*' << std::endl;
    //
    // if (_data.size() <= other._data.size()) {
    //     for (int row = 0; row < _data.size(); row++) {
    //         for (int col = 0; row < _data[row].size(); col++) {
    //             this->_data[row][col] *= other._data[row][col];
    //         }
    //     }
    // }
    // else {
    //     for (int row = 0; row < other._data.size(); row++) {
    //         for (int col = 0; row < other._data[row].size(); col++) {
    //             this->_data[row][col] *= other._data[row][col];
    //         }
    //     }
    // }
    applyOperation(_data, other._data, mul);
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &other) {
    // if (_data.size() <= other._data.size()) {
    //     for (int row = 0; row < _data.size(); row++) {
    //         for (int col = 0; row < _data[row].size(); col++) {
    //             this->_data[row][col] -= other._data[row][col];
    //         }
    //     }
    // }
    // else {
    //     for (int row = 0; row < other._data.size(); row++) {
    //         for (int col = 0; row < other._data[row].size(); col++) {
    //             this->_data[row][col] -= other._data[row][col];
    //         }
    //     }
    // }
    applyOperation(_data, other._data, sub);
    return *this;
}

Matrix &Matrix::operator/=(const Matrix &other) {
    // if (_data.size() <= other._data.size()) {
    //     for (int row = 0; row < _data.size(); row++) {
    //         for (int col = 0; row < _data[row].size(); col++) {
    //             this->_data[row][col] /= other._data[row][col];
    //         }
    //     }
    // }
    // else {
    //     for (int row = 0; row < other._data.size(); row++) {
    //         for (int col = 0; row < other._data[row].size(); col++) {
    //             this->_data[row][col] /= other._data[row][col];
    //         }
    //     }
    // }
    applyOperation(_data, other._data, divide);
    return *this;
}