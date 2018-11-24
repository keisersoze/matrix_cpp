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
    matrix_tail(const vector<E> &data,const int &r, const int &c) {
        decorated_matrix = make_unique < base_matrix_impl <E> >(data,r,c);
    }

    /**
     * !!!!!!!
     * 1) Create a new decorated matrix passing the ownership of the matrix pointed by @decorated_matrix
     * 2) Assign to @decorated_matrix (that now point to null) the ownership of the matrix created in 1
     */
    void transpose(){
        decorated_matrix.reset(new transposed_matrix_impl <E> (move(decorated_matrix)));
    }

    void diagonal(){
        decorated_matrix.reset(new diagonal_matrix_impl <E> (move(decorated_matrix)));
    }

    E get(int accessed_row, int accessed_column){
        return decorated_matrix->get(accessed_row,accessed_column);
    }
};

template < typename E>
class matrix {

private:

    shared_ptr < matrix_tail <E> > matrix_tail_instance;



public:

    matrix(const vector<E> &data,const int &r, const int &c) {
        matrix_tail_instance = make_shared <matrix_tail <E>> (data,r,c);
    }

    E get(int accessed_row, int accessed_column){
        return matrix_tail_instance->get(accessed_row,accessed_column);
    }

    //TODO no side effects
    matrix& transpose(){
        matrix_tail_instance->transpose();
        return *this;
    }

    matrix diagonal(){
        matrix_tail_instance->diagonal();
        return *this;
    }

};



#endif //MATRIX_CPP_MATRIX_WRAPPER_H
