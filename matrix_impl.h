//
// Created by Filippo Maganza on 21/11/2018.
//

#ifndef MATRIX_CPP_MATRIX_IMPL_H
#define MATRIX_CPP_MATRIX_IMPL_H

#include "matrix.h"
#include "transposed_matrix.h"

template<typename E, int r, int c>
matrix <E, c, r> matrix<E, r, c>::transpose() {
    transposed_matrix<E, c, r> temp_matrix (this);
    return temp_matrix;
}

#endif //MATRIX_CPP_MATRIX_IMPL_H
