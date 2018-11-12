//
// Created by Filippo Maganza on 12/11/2018.
//

#ifndef MATRIX_CPP_MATRIX_H
#define MATRIX_CPP_MATRIX_H

#include <array>
#include <ostream>

template <class E, int m1, int n1> class Matrix {
private:

    std::shared_ptr <std::array<E,n1*m1>> matrix_ptr;

    bool transposed;
    bool diagonalized;
    int m_;
    int n_;

    Matrix(const std::shared_ptr<std::array<E, n1 * m1>> &matrix_ptr);

public:

    Matrix(const E Matrix[m1][n1]);

    virtual ~Matrix();

    void setTransposed(bool transposed);

    void setDiagonalized(bool diagonalized);

    //matrix<E> submatrix(int n, int m);
    Matrix<E, n1, m1> transpose();
    Matrix<E, m1, n1> diagonal();
    const Matrix <E, m1, n1> diagonalMatrix();


    //only for testing purpose
    void print ();
};



#endif //MATRIX_CPP_MATRIX_H
