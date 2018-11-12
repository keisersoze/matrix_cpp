//
// Created by Filippo Maganza on 12/11/2018.
//

#ifndef MATRIX_CPP_MATRIX_H
#define MATRIX_CPP_MATRIX_H

#include <array>

template <class E, int m, int n> class Matrix {
private:
    std::array<E,n*m> v;
public:
    Matrix();
    virtual ~Matrix();
    Matrix (const Matrix &matrix);

    void submatrix(int n1, int m1);
    void transpose();
    void diagonal();
    void diagonalMatrix();



};



#endif //MATRIX_CPP_MATRIX_H
