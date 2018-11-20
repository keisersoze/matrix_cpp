//
// Created by Filippo Maganza on 19/11/2018.
//

#ifndef MATRIX_CPP_TRANSPOSED_MATRIX_H
#define MATRIX_CPP_TRANSPOSED_MATRIX_H

#include "matrix.h"
template <typename E, int r, int c>
class transposed_matrix : public /* protected private */ matrix < E , c , r> { // by_arn:sicuro che può essere public? significa che può essere creata dall'utente. penso dovrebbe essere "protected" o "private". Consiglio di tenerla public e quando testiamo proviamo a cambiare l'impostazione.

private:
    matrix<E, r, c> *wrapped_matrix;

public:

    transposed_matrix(matrix<E, r, c> *matrix);

    E operator()(int accessed_row, int accessed_column);
};


#endif //MATRIX_CPP_TRANSPOSED_MATRIX_H
