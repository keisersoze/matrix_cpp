//
// Created by Filippo Maganza and Arnaldo Santoro
//

#include "matrix_impl.h"

template < typename E>
class row_matrix_iterator{

private:

    shared_ptr < matrix_impl <E> > shared_ptr1;
    unsigned cr;
    unsigned cc;

public:

    row_matrix_iterator(shared_ptr<matrix_impl<E>> matrix_ptr, unsigned r, unsigned c)
            : shared_ptr1(matrix_ptr) , cr(r) , cc(c) {}

    row_matrix_iterator& operator ++(){
        cc++;
        if (cc == shared_ptr1->getColumnNumber() + 1) {
            cc = 1;
            cr++;
        }
        return *this;
    }

    row_matrix_iterator& operator ++(int){
        row_matrix_iterator tmp(*this);
        operator++();
        return tmp;
    }

    const E& operator *(){
        return shared_ptr1->get_ref(cr,cc);
    }

    bool operator == (const row_matrix_iterator& x){
        return cc == x.cc && cr == x.cr;
    }

    bool operator != (const row_matrix_iterator& x){
        return ! operator == (x);
    }

};

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
        cr++;
        if (cr == shared_ptr1->getColumnNumber() + 1) {
            cr = 1;
            cc++;
        }
        return *this;
    }

    column_matrix_iterator& operator ++(int){
        column_matrix_iterator tmp(*this);
        operator++();
        return tmp;
    }

    const E& operator *(){
        return shared_ptr1->get_ref(cr,cc);
    }

    bool operator == (const column_matrix_iterator& x){
        return cc == x.cc && cr == x.cr;
    }

    bool operator != (const column_matrix_iterator& x){
        return ! operator == (x);
    }

};