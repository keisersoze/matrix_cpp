//
// Created by Filippo Maganza on 22/11/2018.
//

#ifndef MATRIX_CPP_MATRIX_WRAPPER_H
#define MATRIX_CPP_MATRIX_WRAPPER_H

#include "matrix_impl.h"

template < typename E>
class matrix_tail{
private:
    unique_ptr < matrix_impl <E> > decorated_matrix;
public:
    matrix_tail(const unique_ptr<matrix_impl<E>> &decorated_matrix) : decorated_matrix(decorated_matrix) {}

    const unique_ptr<matrix_impl<E>> &getDecorated_matrix() const {
        return decorated_matrix;
    }

};

template < typename E>
class matrix {

private:

    shared_ptr < matrix_impl <E> > matrix_tail_instance;

public:

    matrix(const vector<E> &data, int r, int c): matrix_tail_instance (new base_matrix_impl<E>(data,r,c)){
    }

    E get(int accessed_row, int accessed_column){
        return matrix_tail_instance -> get(accessed_row,accessed_column);
    }

    matrix* transpose(){
        matrix_tail_instance.reset(new transposed_matrix_impl <E> (matrix_tail_instance));
        return this;
    }

};



#endif //MATRIX_CPP_MATRIX_WRAPPER_H
