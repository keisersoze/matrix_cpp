//
// Created by Arnaldo Santoro on 19/11/2018.
//

#include "submatrix.h"

template <typename E, int r, int c>
submatrix(matrix<E, r, c> *matrix, int upper_row, int upper_col){
    if (upper_row > lower_row || upper_col > lower_col || sub_r != lower_row - upper_row + 1 || sub_c != lower_col - upper_col + 1 ){
        // throw Bad_size();
    }else {
        wrapped_matrix = matrix;
        row_offset = upper_row -1;
        col_offset = upper_col -1;
    }
}

template<typename E, int r, int c>
E submatrix<E, r, c>::operator()(int accessed_row, int accessed_column) {
    return wrapped_matrix->at(accessed_row + row_offset, accessed_column + col_offset);
}