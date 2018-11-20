//
// Created by Arnaldo Santoro on 19/11/2018.
//

#ifndef MATRIX_CPP_SUBMATRIX_H
#define MATRIX_CPP_SUBMATRIX_H

#include "matrix.h"

//by_arn: ho copiato il file transposed_matrix e modificato ad hoc per submatrix 

template <typename E, int r, int c>
class submatrix : public /* protected private */ matrix < E , c , r> { // by_arn: sicuro che può essere public? significa che può essere creata dall'utente. penso dovrebbe essere "protected" o "private". Consiglio di tenerla public e quando testiamo proviamo a cambiare l'impostazione.

private:
    matrix<E, r, c> *wrapped_matrix;
    int row_offset, col_offset;
public:

    submatrix(matrix<E, r, c> *matrix, int upper_row, int upper_col, int lower_row, int lower_col); // prende in input la wrapped matrix e la posizione del primo elemento e dell'ultimo elemento della sottomatrice.

    E operator()(int accessed_row, int accessed_column);
};


#endif //MATRIX_CPP_SUBMATRIX_H
