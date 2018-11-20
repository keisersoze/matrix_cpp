# matrix_cpp

/*
    Assignment 1: Matrix Library

Due date: 11/11/2018

Implement a templated library handling matrices, vectors, and covectors; where vectors are nx1 matrices and covectors are 1xn matrices.

the library must offer operation like:

    submatrix: return a base_matrix that contains a contiguous subrange of rows and columns of the original base_matrix
    transpose: return a base_matrix with rows and columns inverted
    diagonal: return a vector containing the diagonal elements of a given base_matrix
    diagonalmatrix: return an unmodifiable diagonal base_matrix whose diagonal elements are those of a given vector

The matrices returned by such operators must share the data with the original base_matrix,
    but direct copy of the matrices and vectors must result in a deep copy 
    (sharing a base_matrix can be obtained by taking a submatrix extending the whole row and column ranges).

Create iterators for the base_matrix traversing it either in row-major or column-major order.
Any base_matrix should be traversable in either direction regardless of its natural representation order.
Any given iterator will traverse only in a given order.
*/

