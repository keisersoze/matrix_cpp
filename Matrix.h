//
// Created by Filippo Maganza on 12/11/2018.
//

#ifndef MATRIX_CPP_MATRIX_H
#define MATRIX_CPP_MATRIX_H

#include <array>

template <class E, int m1, int n1> class Matrix {
private:
    std::shared_ptr <std::array<E,n1*m1>> matrix_ptr;
    bool transposed;
    bool diagonalized;
    int m2;
    int n2;
public:
    Matrix();
    virtual ~Matrix();
    Matrix (const Matrix &matrix);

    Matrix submatrix(int n, int m);
    Matrix transpose();
    Matrix diagonal();
    const Matrix diagonalMatrix();

};



#endif //MATRIX_CPP_MATRIX_H
