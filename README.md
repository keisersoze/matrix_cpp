Assignment 1: Matrix Library

Due date: 27/11/2018 

Implement a templated library handling matrices, vectors, and covectors; where vectors are nx1 matrices and covectors are 1xn matrices.

the library must offer operation like:

* submatrix: return a matrix that contains a contiguous subrange of rows and columns of the original matrix
* transpose: return a matrix with rows and columns inverted
* diagonal: return a vector containing the diagonal elements of a given matrix
* diagonalmatrix: return an unmodifiable diagonal matrix whose diagonal elements are those of a given vector

The matrices returned by such operators must share the data with the original matrix, but direct copy of the matrices and vectors must result in a deep copy (sharing a matrix can be obtained by taking a submatrix extending the whole row and column ranges).

Create forward iterators for the matrix traversing it either in row-major or column-major order. Any matrix should be traversable in either direction regardless of its natural representation order. Any given iterator will traverse only in a given order.

##ASSUMPTIONS

* vectors are nx1 matrix
* covectors are 1xn matrix

##USAGE

Initialize a new matrix:

``` c++
std::vector < int > a = {1,2,3,4,5,6};
matrix < int > m (a,2,3);
```

* Elements are accessed through the get(int accessed_row, int accessed_column) //and () operator// function, which uses the input to access the vector data at the corresponding position.
     It's created by giving a vector<E> and two <int>'s as row and columns;
             E.g.:
                 matrix<double> m(vector_of_9_elements,3,3);
                 m.get(2,1);
                 
                 
    E.g.:
            m.diagonal().get(3,1); // OK 
            m.diagonal().get(3,2); // ERROR
            
            
                    E.g.:
                        m.submatrix(); // not advisable
                        m.submatrix(pair<int, int> (2,2),pair<int, int>(3,3)); // returns a 2x2 matrix
                        m.submatrix(pair<int, int> (2,2),pair<int, int>(3,3)).get(1,2) == m.get(2,3) // true



##DESIGN

###Decorator design pattern

Our matrix template has been designed with the decorator pattern. In particular we have implemented this pattern using the dynamic polymorphism offered by c++ :

* matrix_impl: is the interface for the base matrix class and the decorator classes. 

* base_matrix_impl: has two integers r and c that represent row and column numbers, and a vector data, of type E, which contains the elemnts of the matrix. 

* transposed_matrix_impl:
        the decoration class for the transposed matrix which has a pointer to the decorated matrix;
        it overrides the accessors calling the same methods to the wrapped matrix with inverted input. 

* diagonal_matrix_impl:
        the decoration class for the transposed matrix which has a shared pointer to the decorated matrix;
        it is a vector (a matrix with r rows and 1 column) accessing elements of the decrated matrix which are on diagonal positions;
    
         
* submatrix_matrix_impl:
        a decoration of the matrix class, which has a shared pointer to the decorated matrix;
        it is a vector which accesses a portion of elements of the decorated matrix.
        its creator takes two pairs of <int>s which refer to the positions of the first and last elements of the matrix;
        its default creator returns a decoration of the matrix with all the elements; it gives therefore no error, but it is not advisable to do so as it lengthen the chain of decorations;

###Shared pointers

###PIMPL idiom
The PIMPL Idiom (Pointer to IMPLementation) is a technique for implementation hiding in which a public class wraps a structure or class that cannot be seen outside the library the public class is part of.

The file matrix.h contains the classes matrix and matrix_temp.
The matrix_temp class has been created to avoid making a deep copy invoking the copy constructor:
It does things in this way so that other thing is accomplished. <-inglese per "fa cose" **FIL**

###Iterators

The file iterator.h contains things. They do things in this way so that other things are done. **FIL**

Errors are const char *, thrown to inform the user. **FIL**
