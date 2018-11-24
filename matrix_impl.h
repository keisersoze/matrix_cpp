//
// Created by Filippo Maganza on 21/11/2018.
//

#ifndef MATRIX_CPP_MATRIX_H
#define MATRIX_CPP_MATRIX_H

#include <vector>
#include <iostream>
#include <memory>

using namespace std;

/* UTILITY FUNCTIONS */

template <typename E> E getZeroElement (){
    return nullptr;
}

template <> int getZeroElement <int> (){
    return 0;
}

template <> double getZeroElement <double> (){
    return 0.;
}

template <> float getZeroElement <float> (){
    return 0.;
}

template <> char getZeroElement <char> (){
    return '0';
}

//TODO possiamo aggiungere ulteriori specilizzazioni, sta alla nostra fantasia

/* INTERFACE */

template < typename E>
class matrix_impl {

public:

    virtual E get(int accessed_row, int accessed_column) = 0; //pure virtual

    virtual int getRowNumber() = 0;

    virtual int getColumnNumber() = 0;

    virtual ~matrix_impl() {};
};

/* BASE MATRIX */

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

/* TRANSPOSED MATRIX */

template <typename E>
class transposed_matrix_impl : public matrix_impl <E>{

private:

    unique_ptr< matrix_impl<E> > matrix_ptr;

public:

    transposed_matrix_impl(unique_ptr < matrix_impl <E> > decorated_matrix_ptr):matrix_ptr(move(decorated_matrix_ptr)){
    }

    int getRowNumber() override {
        return matrix_ptr->getColumnNumber();
    }

    int getColumnNumber() override {
        return matrix_ptr->getRowNumber();
    }

    E get(int accessed_row, int accessed_column) override {
        if (accessed_row < 1 || accessed_row > getRowNumber()) {
            throw "Out of bound row index";
        } else if (accessed_column < 1 || accessed_column > getColumnNumber()) {
            throw "Out of bound column index";
        } else
            return matrix_ptr->get(accessed_column, accessed_row);
    }

};


/* DIAGONAL MATRIX */

template <typename E>
class diagonal_matrix_impl : public matrix_impl <E>{

private:

    unique_ptr< matrix_impl<E> > matrix_ptr;

public:

    diagonal_matrix_impl(unique_ptr < matrix_impl <E> > decorated_matrix_ptr):matrix_ptr(move(decorated_matrix_ptr)){
    }

    int getRowNumber() override {
        return matrix_ptr->getRowNumber();
    }

    int getColumnNumber() override {
        return 1;
    }

    E get(int accessed_row, int accessed_column) override {
        if (accessed_row < 1 || accessed_row > getRowNumber()) {
            throw "Out of bound row index";
        } else if (accessed_column != 1) {
            throw "Out of bound column index"; //TODO i messaggi vanno migliorati
        } else {
            return matrix_ptr->get(accessed_row, accessed_row);
        }
    }
};

/* SUBMATRIX */


template <typename E>
class submatrix_impl : public matrix_impl <E>{

private:

    unique_ptr< matrix_impl<E> > matrix_ptr;

public:

    submatrix_impl(unique_ptr < matrix_impl <E> > decorated_matrix_ptr):matrix_ptr(move(decorated_matrix_ptr)){
    }

    int getRowNumber() override {
        return matrix_ptr->getRowNumber();
    }

    int getColumnNumber() override {
        return matrix_ptr->getColumnNumber();
    }

    E get(int accessed_row, int accessed_column) override {

    }
};



#endif //MATRIX_CPP_MATRIX_H