//
// Created by Filippo Maganza on 21/11/2018.
//

#ifndef MATRIX_CPP_MATRIX_H
#define MATRIX_CPP_MATRIX_H

#include <vector>
#include <iostream>
#include <memory>

using namespace std;

template < typename E>
class matrix_impl {

public:

    virtual E get(int accessed_row, int accessed_column) = 0;

};


template < typename E>
class base_matrix_impl : public matrix_impl <E>{

private:

    int r;
    int c;
    vector < E > data;

public:

    base_matrix_impl(const vector<E> &data, int r, int c) : r(r), c(c), data(data) {}

    E get(int accessed_row, int accessed_column) {
        if (accessed_row < 1) {
            // return nullptr; by_arn dovrebbe ritornare un errore
            // throw Bad_input{};
        } else if (accessed_column < 1) {
            //return nullptr; by_arn dovrebbe ritornare un errore
            // throw Bad_input{};
        } else if (accessed_row > r || accessed_column > c) {
            //return nullptr; by_arn dovrebbe ritornare un errore
            // throw Bad_input{};
        } else
            return data[c * (accessed_row - 1) + accessed_column - 1];
    }

};

template <typename E>
class transposed_matrix_impl : public matrix_impl <E>{ // by_arn:sicuro che può essere public? significa che può essere creata dall'utente. penso dovrebbe essere "protected" o "private". Consiglio di tenerla public e quando testiamo proviamo a cambiare l'impostazione.

private:

    matrix_impl<E> *wrapped_matrix; //utilzzare smart pointers (unique)

public:

    transposed_matrix_impl(matrix_impl<E> *matrix){
        wrapped_matrix = matrix;
    }

    E get(int accessed_row, int accessed_column) {
        return wrapped_matrix->get(accessed_column, accessed_row);
    }

};

#endif //MATRIX_CPP_MATRIX_H