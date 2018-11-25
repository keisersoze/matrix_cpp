**FIL_AGGIUNGI_DETTAGLI**
// anche in italiano e io traduco.
// basta cercare **FIL**.
// per richiamare la mia attenzione usa **ARN** <-cambialo se vuoi
Assignment 1: Matrix Library

Due date: 27/11/2018 

Implement a templated library handling matrices, vectors, and covectors; where vectors are nx1 matrices and covectors are 1xn matrices.

the library must offer operation like:

submatrix: return a matrix that contains a contiguous subrange of rows and columns of the original matrix
transpose: return a matrix with rows and columns inverted
diagonal: return a vector containing the diagonal elements of a given matrix
diagonalmatrix: return an unmodifiable diagonal matrix whose diagonal elements are those of a given vector
The matrices returned by such operators must share the data with the original matrix, but direct copy of the matrices and vectors must result in a deep copy (sharing a matrix can be obtained by taking a submatrix extending the whole row and column ranges).

Create iterators for the matrix traversing it either in row-major or column-major order. Any matrix should be traversable in either direction regardless of its natural representation order. Any given iterator will traverse only in a given order.

**IMPLEMENTATION**

Our matrix class is implemented using a decorator design pattern.
The classes used in the matrix_impl.h are:
    - matrix_impl: abstract class of which the following subclasses are implementations. 
    - base_matrix_impl:
        an implementation of a matrix; has two integers r and c that represent row and column numbers, and a vector data, of type E, which contains the elemnts of the matrix.
        Elements are accessed through the get(int accessed_row, int accessed_column) //and () operator// function, which uses the input to access the vector data at the corresponding position.
        It's created by giving a vector<E> and two <int>'s as row and columns;
        E.g.:
            matrix<double> m(vector_of_9_elements,3,3);
            m.get(2,1);
        The following classes are decorations, which means they have a matrix - a shared pointer to the decorated matrix - and they are a matrix, and implement the transpose, submatrix, and diagonal functions;

    - transposed_matrix_impl:
        a decoration of the matrix class, which has a shared pointer to the decorated matrix;
        it overloads the accessors inverting the input and passing it to the decorated matrix_impl. 
        E.g.:
            m.transpose().get(1,2);
    
    - diagonal_matrix_impl:
        a decoration of the matrix class, which has a shared pointer to the decorated matrix;
        it is a vector (a matrix with r rows and 1 column) accessing elements of the decrated matrix which are on diagonal positions;
        E.g.:
            m.diagonal().get(3,1); // OK 
            m.diagonal().get(3,2); // ERROR
         
    - submatrix_matrix_impl:
        a decoration of the matrix class, which has a shared pointer to the decorated matrix;
        it is a vector which accesses a portion of elements of the decorated matrix.
        its creator takes two pairs of <int>s which refer to the positions of the first and last elements of the matrix;
        its default creator returns a decoration of the matrix with all the elements; it gives therefore no error, but it is not advisable to do so as it lengthen the chain of decorations;
        E.g.:
            m.submatrix(); // not advisable
            m.submatrix(pair<int, int> (2,2),pair<int, int>(3,3)); // returns a 2x2 matrix
            m.submatrix(pair<int, int> (2,2),pair<int, int>(3,3)).get(1,2) == m.get(2,3) // true

The file matrix.h contains the classes matrix and matrix_temp.
The matrix_temp class has been created to avoid making a deep copy invoking the copy constructor:
It does things in this way so that other thing is accomplished. <-inglese per "fa cose" **FIL**

The file iterator.h contains things. They do things in this way so that other things are done. **FIL**

