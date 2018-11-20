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
    shared_ptr < array <  E , c * r > > matrix_ptr;

public:

    matrix();

    matrix(const array<E, c * r > &array);

    E at (int accessed_row, int accessed_column); //by_arn: non è virtual? sicuro?

    virtual E operator()(int accessed_row, int accessed_column);

    matrix<E, c, r>* transpose(); // by_arn: non ritorna una transposed_matrix?

    //inizio codice di arn
    /* ERRORE: cosa scrivo nel tipo di ritorno? deve ritornare una matrice <E, intero_non_conosciuto, intero_non_conosciuto > */
    matrix< E, sub_r, sub_c >* submatrix(int upper_row, int upper_col, int lower_row, int lower_col); //by_arn  
    //fine codice di arn 

    //matrix

    void print ();
};

#endif // MATRIX_CPP_MATRIX_H