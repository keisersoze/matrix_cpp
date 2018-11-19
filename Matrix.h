//
// Created by Filippo Maganza on 12/11/2018.
//

#ifndef MATRIX_CPP_MATRIX_H
#define MATRIX_CPP_MATRIX_H

#include <array>
#include <iostream>
#include <memory>

using namespace std;

template <typename E, int r, int n>
class Matrix {

    static_assert(r > 0, "Brutto deficiente");
    static_assert(n > 0, "Brutto deficiente");


private:
    //class Bad_Input{}; // to throw errors, for example when m1 < 1
    shared_ptr < array <  E , n * r > > matrix_ptr; //by_arn: explaination needed...?

public:

    Matrix(const array<E, n * r > &array) {
        matrix_ptr = std::make_shared<std::array<E, n * r > >(array);
    }

    E at (int accessed_row, int accessed_column){
        array<E, n * r > v = *(matrix_ptr.get());
        if(accessed_row < 1) {
            //throelse
        }else if (accessed_column < 1){
            //
        }else
            return v[ n * (accessed_row - 1) + accessed_column - 1];
    };

    E operator()(int accessed_row, int accessed_column){
        return at(accessed_row,accessed_column);
    };










    // Getters

    //E get(int r_index, int c_index);

    //E operator()(int r_index, int c_index);

    //matrix<E> submatrix(int n, int m);
    //Matrix<E, n1, m1> transpose();
    //Matrix<E, m1, n1> diagonal();
    //const Matrix <E, m1, n1> diagonalMatrix();

    //only for testing purpose
    void print (){
        array<int, n * r> array= *(matrix_ptr.get());
        for (int i = 0; i < n * r; ++i) {
            std::cout << array[i] << ' ';
        }


    }
};


#endif //MATRIX_CPP_MATRIX_H
