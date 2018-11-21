//
// Created by Filippo Maganza on 12/11/2018.
//

#ifndef BASE_MATRIX_CPP_MATRIX_H
#define BASE_MATRIX_CPP_MATRIX_H

#include <array>
#include <iostream>
#include <memory>
#include "matrix.h"

using namespace std;


template < typename E, int r, int c>
class base_matrix : public matrix <E ,r , c> {

private:

    shared_ptr < array <  E , c * r > > matrix_ptr;

public:

    base_matrix(){
    }

    base_matrix(const array<E, c * r > &array){
        matrix_ptr = std::make_shared<std::array<E, c * r > >(array);
    }

    E at(int accessed_row, int accessed_column) {
        array < E, c * r > v = *(matrix_ptr.get());
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
            return v[c * (accessed_row - 1) + accessed_column - 1];
    }

    E operator()(int accessed_row, int accessed_column){
        return at(accessed_row,accessed_column);
    }

};

#endif // MATRIX_CPP_MATRIX_H