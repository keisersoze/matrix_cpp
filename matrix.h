//
// Created by Filippo Maganza on 12/11/2018.
//

#ifndef MATRIX_CPP_MATRIX_H
#define MATRIX_CPP_MATRIX_H

#include <array>
#include <iostream>
#include <memory>

using namespace std;

/**
 * Declaration of matrix
 * @tparam E
 * @tparam r
 * @tparam c
 */

template < typename E, int r, int c>
class matrix {

    typedef E type;

    static_assert(r > 0, "r parameter should be > 0");
    static_assert(c > 0, "c parameter should be > 0");


private:
    //class Bad_Input{}; // to throw errors, for example when m1 < 1
    shared_ptr < array <  E , c * r > > matrix_ptr;

public:

    matrix();

    matrix(const array<E, c * r > &array);

    E at (int accessed_row, int accessed_column); //by_arn: non è virtual? sicuro?

    virtual E operator()(int accessed_row, int accessed_column);

    matrix<E, c, r>* transpose(); // by_arn: non ritorna una transposed_matrix?

    void print ();
};

/**
 * Declaration of transposed_matrix
 * @tparam E
 * @tparam r
 * @tparam c
 */

template <typename E, int r, int c>
class transposed_matrix : public /* protected private */ matrix < E , c , r> { // by_arn:sicuro che può essere public? significa che può essere creata dall'utente. penso dovrebbe essere "protected" o "private". Consiglio di tenerla public e quando testiamo proviamo a cambiare l'impostazione.

private:
    matrix<E, r, c> *wrapped_matrix;

public:

    transposed_matrix(matrix<E, r, c> *matrix);

    E operator()(int accessed_row, int accessed_column);
};


/**
 * Declaration of submatrix
 * @tparam E
 * @tparam r
 * @tparam c
 */
template <typename E, int r, int c>
class submatrix : public /* protected private */ matrix < E , c , r> { // by_arn: sicuro che può essere public? significa che può essere creata dall'utente. penso dovrebbe essere "protected" o "private". Consiglio di tenerla public e quando testiamo proviamo a cambiare l'impostazione.

private:
    matrix<E, r, c> *wrapped_matrix;
    int row_offset, col_offset;
public:

    submatrix(matrix<E, r, c> *matrix, int upper_row, int upper_col, int lower_row, int lower_col); // prende in input la wrapped matrix e la posizione del primo elemento e dell'ultimo elemento della sottomatrice.

    E operator()(int accessed_row, int accessed_column);
};


/**
 * Implementation of matrix
 */

template<typename E, int r, int c>
matrix<E, r, c>::matrix() {
}

template<typename E, int r, int c>
matrix<E, r, c>::matrix(const array<E, c * r> &array) {
    matrix_ptr = std::make_shared<std::array<E, c * r > >(array);
}


template<typename E, int r, int c>
E matrix<E, r, c>::at(int accessed_row, int accessed_column) {
    array<E, c * r > v = *(matrix_ptr.get());
    if(accessed_row < 1) {
        // return nullptr; by_arn dovrebbe ritornare un errore
        // throw Bad_input{};
    }else if (accessed_column < 1){
        //return nullptr; by_arn dovrebbe ritornare un errore
        // throw Bad_input{};
    }else if ( accessed_row > r || accessed_column > c ){
        //return nullptr; by_arn dovrebbe ritornare un errore
        // throw Bad_input{};
    }else
        return v[ c * (accessed_row - 1) + accessed_column - 1];
}

template<typename E, int r, int c>
E matrix<E, r, c>::operator()(int accessed_row, int accessed_column) {
    return at(accessed_row,accessed_column);
}


template<typename E, int r, int c>
void matrix<E, r, c>::print() {
    array<int, c * r> array= *(matrix_ptr.get());
    for (int i = 0; i < c * r; ++i) {
        std::cout << array[i] << ' ';
    }
}

template<typename E, int r, int c>
matrix<E, c, r>* matrix<E, r, c>::transpose() {
    return new transposed_matrix<E, r, c>(this);
}

/**
 * Implementation of transposed_matrix
 */

template<typename E, int r, int c>
transposed_matrix<E, r, c>::transposed_matrix(matrix<E, r, c> *matrix) {
    wrapped_matrix = matrix;
}

template<typename E, int r, int c>
E transposed_matrix<E, r, c>::operator()(int accessed_row, int accessed_column) {
    return wrapped_matrix->at(accessed_column, accessed_row);
}

/**
 * Implementation of submatrix
 */
/*
template <typename E, int r, int c>
submatrix<E, r, c>::submatrix(matrix<E, r, c> *matrix, int upper_row, int upper_col){
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
*/


/*
 * TODO codice di arn
 */

//inizio codice di arn
// ERRORE: cosa scrivo nel tipo di ritorno? deve ritornare una matrice <E, intero_non_conosciuto, intero_non_conosciuto >
//matrix< E, sub_r, sub_c >* submatrix(int upper_row, int upper_col, int lower_row, int lower_col); //by_arn
//fine codice di arn

//inizio codice di arn
/* cosa scrivo nel tipo di ritorno? deve ritornare una matrice di dimensione non conosciuta fino alla chiamata della funzione
matrix<E, sub_r, sub_c >* Matrix<E, r, c>::submatrix(int upper_row, int upper_col, int lower_row, int lower_col){
    return new submatrix< E, sub_r, sub_c>(this, upper_row, upper_col, lower_row, lower_col);
}   */
//fine codice di arn

#endif // MATRIX_CPP_MATRIX_H