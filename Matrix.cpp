//
// Created by Filippo Maganza on 12/11/2018.
//

#include <iostream>
#include "Matrix.h"
using namespace std; // Usually it's bad practice to use "using namespace" in header files, but std is an exception.

template<class E, int m1, int n1>
Matrix<E, m1, n1>::Matrix(const E matrix[m1][n1]) {
    vector<E,n1*m1> *vector =matrix_ptr.get();
    for (int i = 0; i < m1 ; ++i) {
        for (int j = 0; j < n1; ++j) {
            vector[i][j] = matrix[j][i];
        }
    }
}

template<class E, int m1, int n1>
Matrix<E, m1, n1>::Matrix(const shared_ptr < vector<E, (n1 * m1) >> &matrix_ptr):matrix_ptr(matrix_ptr) { // by_arn type error? not sure if I've done it
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
    Matrix<E, n1, m1> matrix(matrix_ptr) ;  // automatically call copy constructor of shared_ptr < vector<E, n1 * m1>> ? I think yes
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
    Matrix<E, n1, m1> matrix(matrix_ptr) ; // automatically call copy constructor of shared_ptr < vector<E, n1 * m1>> ? I think yes
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
        cout << 1;
    }

}

//Getters

template<class E, int m1, int n1>
int Matrix<E, m1, n1>::get_row() {
    return Matrix::transposed? n1 : m1;     // rewrite if bools desappear from implementation
}

template<class E, int m1, int n1>
int Matrix<E, m1, n1>::get_column() {
    return Matrix::transposed? m1 : n1;     // rewrite if bools desappear from implementation
}

template<class E, int m1, int n1>
E Matrix<E, m1, n1>::get(int r_index, int c_index){
    if(!Matrix::transposed)
        return matrix_ptr[ (r_index-1)*m1+c_index-1 ]; // by_arn CHECK!! function returns element of matrix in position (r_index,c_index) by acceding to the shared_ptr vector matrix_ptr.
    else
        return matrix_ptr[(c_index-1)*n1 + r_index-1];
}

template<class E, int m1, int n1>
E Matrix<E, m1, n1>::operator()(int r_index, int c_index){
    return Matrix<E, m1, n1>::get(r_index, c_index);
}

// by_arn Proposta: usiamo row, column, r_index e c_index per evitare confusione coi nomi? m e n n1 m1 i j sono potenziale causa di confusione ed errori.




