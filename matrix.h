//
// Created by Filippo Maganza on 22/11/2018.
//

#ifndef MATRIX_CPP_MATRIX_WRAPPER_H
#define MATRIX_CPP_MATRIX_WRAPPER_H

#include "matrix_impl.h"

template < typename E>
class matrix {

private:

    shared_ptr < matrix_impl <E> > m;

public:

    matrix(const vector<E> &data, int r, int c){
        m = make_shared < base_matrix_impl <E> > (data,r,c);
    }

    E get(int accessed_row, int accessed_column){
        return m -> get(accessed_row,accessed_column);
    }

    matrix transpose(){
        m = make_shared < transposed_matrix_impl <E> > (m.get());
    }




};

#endif //MATRIX_CPP_MATRIX_WRAPPER_H
