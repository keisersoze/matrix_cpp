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
    // OCCHIO
    const E zero = 0; 
    // Noi vogliamo che in ogni punto non diagonale (row != col) la matrice ritorni 0. Ovviamente preimpostarlo a 0 non va bene per gli oggetti diversi da numeri e caratteri (già con le stringhe dà errori).
    // soluzione: inserire il parametro nel costruttore della diagonale!

public:

    diagonal_matrix_impl(shared_ptr < matrix_impl <E> > decorated_matrix_ptr):matrix_ptr(decorated_matrix_ptr){
    }

    int getRowNumber() override {
        return matrix_ptr->getRowNumber();
    }

    int getColumnNumber() override {
        return matrix_ptr->getColumnNumber();
    }

    E get(int accessed_row, int accessed_column) override {
        if (accessed_row < 1 || accessed_row > getRowNumber()) {
            throw "Out of bound row index";
        } else if (accessed_column < 1 || accessed_column > getColumnNumber()) {
            throw "Out of bound column index"; //TODO i messaggi vanno migliorati 
            // I messaggi, almeno a me, non funzionano: si dovrebbe lanciare un oggetto "Bad_Size"
        } else {
            return (accessed_column == accessed_row)? matrix_ptr->get(accessed_row, accessed_column) : zero; 
        }
    }

};

/* SUBMATRIX MATRIX */

template <typename E>
class submatrix_matrix_impl : public matrix_impl <E>{

private:

    shared_ptr< matrix_impl<E> > matrix_ptr;
    //i due stati seguenti servono per chiamare il get con le dimensioni della sottomatrice.
    //vanno impostati a " riga_del_primo_elemento_della_sottomatrice - 1 " e " colonna_del_primo_elemento_della_sottomatrice - 1 ".
    int row_offset;
    int column_offset;
    // dimensioni della sottomatrice.
    // le dimensioni della sottomatrice servono per controllare che non vada out_of_bound nella sottomatrice
    // e.g.: in una sottomatrice 2x2 di una matrice 5x5 non dovrei poter trovare l'elemento che si trova in (4,4).
    int sub_r;
    int sub_c;
    
public:

   submatrix_matrix_impl(shared_ptr < matrix_impl <E> > decorated_matrix_ptr):matrix_ptr(decorated_matrix_ptr){
    }

    int getRowNumber() override {
        return sub_r;
    }

    int getColumnNumber() override {
        return sub_c;
    }

    E get(int accessed_row, int accessed_column) override {
        if (accessed_row < 1 || accessed_row > getRowNumber()) {
            throw "Out of bound row index";
        } else if (accessed_column < 1 || accessed_column > getColumnNumber()) {
            throw "Out of bound column index"; //TODO i messaggi vanno migliorati
        } else {
            return matrix_ptr->get(accessed_row + row_offset, accessed_column + column_offset);
        }
    }
};
