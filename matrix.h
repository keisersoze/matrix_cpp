//
// Created by Filippo Maganza on 21/11/2018.
//

#ifndef MATRIX_CPP_MATRIX_H
#define MATRIX_CPP_MATRIX_H

template < typename E, int r, int c>
class matrix {

public:
    E at (int accessed_row, int accessed_column);

    E operator()(int accessed_row, int accessed_column);

    matrix <E, c, r> transpose();
};

#endif //MATRIX_CPP_MATRIX_H