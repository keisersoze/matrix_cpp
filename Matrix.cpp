//
// Created by Filippo Maganza on 12/11/2018.
//

#include <iostream>
#include "Matrix.h"

template<class E, int m1, int n1>
Matrix<E, m1, n1>::Matrix(const E matrix[m1][n1]) {
    std::array<E,n1*m1> *array =matrix_ptr.get();
    for (int i = 0; i < m1 ; ++i) {
        for (int j = 0; j < n1; ++j) {
            array[i][j] = matrix[j][i];
        }
    }
}

template<class E, int m1, int n1>
Matrix<E, m1, n1>::Matrix(const std::shared_ptr<std::array<E, n1 * m1>> &matrix_ptr):matrix_ptr(matrix_ptr) {
    transposed = false;
    diagonalized = false;
    n_=n1;
    m_=m1;
}

/**
 * run in O(1)
 * @tparam E
 * @tparam m1
 * @tparam n1
 * @return
 */
template<class E, int m1, int n1>
Matrix<E, n1, m1> Matrix<E, m1, n1>::transpose() {
    Matrix<E, n1, m1> matrix(matrix_ptr) ; // automatically call copy constructor of std::shared_ptr<std::array<E, n1 * m1>> ? I think yes
    matrix.setTransposed(true);
    return matrix;
}

/**
 * run in O(1)
 * @tparam E
 * @tparam m1
 * @tparam n1
 * @return
 */
template<class E, int m1, int n1>
Matrix<E, m1, n1> Matrix<E, m1, n1>::diagonal() {
    Matrix<E, n1, m1> matrix(matrix_ptr) ; // automatically call copy constructor of std::shared_ptr<std::array<E, n1 * m1>> ? I think yes
    matrix.setDiagonalized(true);
    return matrix;
}

// Setters

template<class E, int m1, int n1>
void Matrix<E, m1, n1>::setTransposed(bool transposed) {
    Matrix::transposed = transposed;
}

template<class E, int m1, int n1>
void Matrix<E, m1, n1>::setDiagonalized(bool diagonalized) {
    Matrix::diagonalized = diagonalized;
}


template<class E, int m1, int n1>
void Matrix<E, m1, n1>::print() {
    for (int i = 0; i < n1*m1 ; ++i) {
        std::cout << 1;
    }

}






