//
// Created by Filippo Maganza on 25/11/2018.
//

#include "matrix_impl.h"

template < typename E>
class column_matrix_iterator{

private:

    shared_ptr < matrix_impl <E> > shared_ptr1;
    unsigned cr;
    unsigned cc;

public:

    column_matrix_iterator(shared_ptr<matrix_impl<E>> matrix_ptr, unsigned r, unsigned c)
    : shared_ptr1(matrix_ptr) , cr(r) , cc(c) {}

    column_matrix_iterator& operator ++(){
        cc++;
        if (cc == shared_ptr1->getColumnNumber()) {
            cc = 1;
            cr++;
        }
        return *this;
    }

    const E& operator *(){
        return shared_ptr1->get(cr,cc);
    }

    bool operator == (const column_matrix_iterator& x){
        return cc == x.cc && cr == x.cr;
    }

    bool operator != (const column_matrix_iterator& x){
        return ! operator == (x);
    }

};