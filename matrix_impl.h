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

    virtual E get(int accessed_row, int accessed_column) = 0; //pure virtual

    virtual int getRowNumber() = 0;

    virtual int getColumnNumber() = 0;


};


template < typename E>
class base_matrix_impl : public matrix_impl <E>{

private:

    int r;
    int c;
    vector < E > data;

public:

    base_matrix_impl(const vector<E> &data, int r, int c) : r(r), c(c), data(data) {}

    int getRowNumber() override {
        return r;
    }

    int getColumnNumber() override {
        return c;
    }

    E get(int accessed_row, int accessed_column) override {
        if (accessed_row < 1 || accessed_row > r) {
            throw "Out of bound row index";
        } else if (accessed_column < 1 || accessed_column > c) {
            throw "Out of bound column index";
        } else
            return data[c * (accessed_row - 1) + accessed_column - 1];
    }

};

template <typename E>
class transposed_matrix_impl : public matrix_impl <E>{ // by_arn:sicuro che può essere public? significa che può essere creata dall'utente. penso dovrebbe essere "protected" o "private". Consiglio di tenerla public e quando testiamo proviamo a cambiare l'impostazione.

private:

    shared_ptr< matrix_impl<E> > matrix_ptr; //TODO unique pointers

public:

    transposed_matrix_impl(shared_ptr < matrix_impl <E> > decorated_matrix_ptr): matrix_ptr(decorated_matrix_ptr){
    }

    int getRowNumber() override {
        return matrix_ptr->getColumnNumber();
    }

    int getColumnNumber() override {
        return matrix_ptr->getRowNumber();
    }

    E get(int accessed_row, int accessed_column) {
        if (accessed_row < 1 || accessed_row > getRowNumber()) {
            throw "Out of bound row index";
        } else if (accessed_column < 1 || accessed_column > getColumnNumber()) {
            throw "Out of bound column index";
        } else
        return matrix_ptr->get(accessed_column, accessed_row);
    }

};

#endif //MATRIX_CPP_MATRIX_H