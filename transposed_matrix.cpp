//
// Created by Filippo Maganza on 19/11/2018.
//

#include "transposed_matrix.h"

template<typename E, int r, int c>
transposed_matrix<E, r, c>::transposed_matrix(matrix<E, r, c> *matrix) {
    wrapped_matrix = matrix;
}

template<typename E, int r, int c>
E transposed_matrix<E, r, c>::operator()(int accessed_row, int accessed_column) {
    return wrapped_matrix->at(accessed_column, accessed_row);
}

