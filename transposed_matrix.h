//
// Created by Filippo Maganza on 20/11/2018.
//

#ifndef MATRIX_CPP_TRANSPOSED_MATRIX_H
#define MATRIX_CPP_TRANSPOSED_MATRIX_H

#include "matrix.h"

template <typename E, int r, int c>
class transposed_matrix : public matrix < E , r , c> { // by_arn:sicuro che può essere public? significa che può essere creata dall'utente. penso dovrebbe essere "protected" o "private". Consiglio di tenerla public e quando testiamo proviamo a cambiare l'impostazione.

private:
    matrix<E, c, r> *wrapped_matrix;

public:

    transposed_matrix(matrix<E, c, r> *matrix){
        wrapped_matrix = matrix;
    }

    transposed_matrix(const transposed_matrix<E, r, c> &transposed_matrix){
        wrapped_matrix = transposed_matrix.wrapped_matrix;
    }

    E operator()(int accessed_row, int accessed_column){
        return (*wrapped_matrix)(accessed_column, accessed_row);
    }
};


#endif //MATRIX_CPP_TRANSPOSED_MATRIX_H