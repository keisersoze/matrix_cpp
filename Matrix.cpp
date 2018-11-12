//
// Created by Filippo Maganza on 12/11/2018.
//

#include "Matrix.h"

template<class E, int m, int n>
Matrix<E, m, n>::Matrix() {
    v= new std::array<E,m*n>;
}

template<class E, int m, int n>
Matrix<E, m, n>::~Matrix() {
    delete v;
}

template<class E, int m, int n>
Matrix<E, m, n>::Matrix(const Matrix &matrix) {

}
