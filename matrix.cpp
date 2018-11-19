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
        //return nullptr;
    }else if (accessed_column < 1){
        //return nullptr;
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
