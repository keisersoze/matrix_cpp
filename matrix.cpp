//
// Created by Filippo Maganza on 19/11/2018.
//

#include "matrix.h"
#include "transposed_matrix.cpp"

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

//inizio codice di arn
/* cosa scrivo nel tipo di ritorno? deve ritornare una matrice di dimensione non conosciuta fino alla chiamata della funzione */
matrix<E, sub_r, sub_c >* Matrix<E, r, c>::submatrix(int upper_row, int upper_col, int lower_row, int lower_col){
    return new submatrix< E, sub_r, sub_c>(this, upper_row, upper_col, lower_row, lower_col);
}   
//fine codice di arn 
