//
// Filippo Maganza and Aranldo Santoro
//

#include <vector>
#include <iostream>
#include <memory>

using namespace std;

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

    shared_ptr< matrix_impl<E> > matrix_ptr;

public:

    transposed_matrix_impl(shared_ptr < matrix_impl <E> > decorated_matrix_ptr):matrix_ptr(decorated_matrix_ptr){
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

    shared_ptr< matrix_impl<E> > matrix_ptr;

public:

    diagonal_matrix_impl(shared_ptr < matrix_impl <E> > decorated_matrix_ptr):matrix_ptr(decorated_matrix_ptr){
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
            // I messaggi, almeno a me, non funzionano: si dovrebbe lanciare un oggetto "Bad_Size"
        } else {
            return matrix_ptr->get(accessed_row, accessed_row);
        }
    }

};

/* SUBMATRIX MATRIX */

template <typename E>
class submatrix_matrix_impl : public matrix_impl <E>{

private:

    shared_ptr< matrix_impl<E> > matrix_ptr;

    int row_offset;
    int column_offset;
    int r;
    int c;
    
public:

   submatrix_matrix_impl(shared_ptr < matrix_impl <E> > decorated_matrix_ptr,
                         pair <int, int > first_pair, pair <int ,int > second_pair)
                         :matrix_ptr(decorated_matrix_ptr){
       if (first_pair.first < 1 || first_pair.second < 1 ||
           second_pair.first > matrix_ptr->getRowNumber() || second_pair.second > matrix_ptr->getColumnNumber() ||
           first_pair.first > second_pair.first || first_pair.second > second_pair.second){
           throw "Invalid submatrix input.";
       } else {
           row_offset = first_pair.first - 1;
           column_offset = first_pair.second - 1;
           r = second_pair.first - first_pair.first + 1;
           c = second_pair.second - first_pair.second + 1;
       }
    }

    int getRowNumber() override {
        return r;
    }

    int getColumnNumber() override {
        return c;
    }

    E get(int accessed_row, int accessed_column) override {
        if (accessed_row < 1 || accessed_row > getRowNumber()) {
            throw "Out of bound row index";
        } else if (accessed_column < 1 || accessed_column > getColumnNumber()) {
            throw "Out of bound column index";
        } else {
            return matrix_ptr->get(accessed_row + row_offset, accessed_column + column_offset);
        }
    }
};
