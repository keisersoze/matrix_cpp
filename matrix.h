//
// Created by Filippo Maganza on 12/11/2018.
//

#ifndef MATRIX_CPP_MATRIX_H
#define MATRIX_CPP_MATRIX_H

#include <array>
#include <iostream>
#include <memory>

using namespace std;


template < typename E, int r, int c>
class matrix {

    typedef E type;

    static_assert(r > 0, "r parameter should be > 0");
    static_assert(c > 0, "c parameter should be > 0");


private:
    //class Bad_Input{}; // to throw errors, for example when m1 < 1
    shared_ptr < array <  E , c * r > > matrix_ptr; //by_arn: explaination needed...?

public:

    matrix();

    matrix(const array<E, c * r > &array);

    E at (int accessed_row, int accessed_column);

    virtual E operator()(int accessed_row, int accessed_column);

    matrix<E, c, r>* transpose();

    void print ();
};

#endif // MATRIX_CPP_MATRIX_H