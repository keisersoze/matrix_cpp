//
// Created by Filippo Maganza on 12/11/2018.
//

#ifndef MATRIX_CPP_MATRIX_H
#define MATRIX_CPP_MATRIX_H

#include <vector>
#include <iostream>
#include <memory>

using namespace std;

template <class E, int m1, int n1> class Matrix {
private:
    class Bad_Input{}; // to throw errors, for example when m1 < 1 
    shared_ptr < vector < E, n1 * m1 > > matrix_ptr; //by_arn: explaination needed...?

    bool transposed;    
    bool diagonalized;
    int m_;
    int n_;

    Matrix(const shared_ptr < vector<E, n1 * m1>> & matrix_ptr);

public:

    Matrix(const E Matrix[m1][n1]);

    virtual ~Matrix();

    void setTransposed(bool transposed);        // by_arn: what are these bools implying for implementation? If you use a setter for transposed you'll cause errors

    void setDiagonalized(bool diagonalized);

    // Getters
    int get_row();

    int get_column();

    E get(int r_index, int c_index);

    E operator()(int r_index, int c_index);

    //matrix<E> submatrix(int n, int m);
    Matrix<E, n1, m1> transpose();
    Matrix<E, m1, n1> diagonal();
    const Matrix <E, m1, n1> diagonalMatrix();

    
    //only for testing purpose
    void print ();
};


#endif //MATRIX_CPP_MATRIX_H
