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
* the diagonalmatrix can

##USAGE

The client code have to manage two different templated classes: `matrix <E>` and its derived class `shared_matrix  <E>` . The only difference is that the formers's copy construct does a deep copy of the data while the latter's copy constructor return a matrix that share data with the original one.

Below are presented all the operation supported by the library.

Initialization a new matrix:

``` c++
std::vector < int > elements_vector_a = {1, 2, 3, 4, 5, 6};
matrix < int > int_matrix (elements_vector_a, 2, 3);

std::vector < double > elements_vector_b = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6};
matrix < double > double_matrix(elements_vector_b, 3, 2);

std::vector < char > elements_vector_c = {'a', 'b', 'd', 'g', 'e', 'g', '', '4', ']'};
matrix < char > char_matrix(elements_vector_c, 3, 3);

matrix < int > error (elements_vector_a, 0, 3); // error: invalid input row
matrix < int > error (elements_vector_a, 2, -1); // error: invalid input column
matrix < int > error (elements_vector_a, 3, 3); // error: invalid input vector

double_matrix.getRowNumber() == 3; // true
double_matrix.getColumnNumber() == 2; // true
```

Access elements of a matrix:

``` c++
double a_double = double_matrix(accessed_row,accessed_column);
```

Assign values to elements:

``` c++
int value;
m(row,column) = value;
```

Copy a matrix:
```
matrix<int> copied_matrix = int_matrix; //Deep copy -> data are NOT shared
auto copied_matrix = double_matrix.transpose(); //Copy with shared data
const auto copied_matrix = int_matrix.diagonal_matrix(); // note the use of const to avoid accessing a const reference
```

Transpose a matrix:
``` c++
double a_double = double_matrix.transpose()
```

Obtain a vector of diagonal elements of a matrix:
``` c++
int_matrix.diagonal();

```

Obtain a const diagonal matrix:
``` c++
int row = 1, column = 2;
const auto constant_diagonal_matrix int_matrix.diagonal_matrix(); //note the use of const

constant_diagonal_matrix(row,column) = 666; // error: unmodifyable matrix
int an_int = constant_diagonal_matrix(row,column);
an_int == 0; // true
constant_diagonal_matrix(2,2) == 5; // true
```

Obtain a submatrix:
``` c++

auto sub_matrix = char_matrix.submatrix( 2,2, 3,3); // obtain a matrix which is a 2x2 submatrix with the element of the base matrix in position 2,2 as first element  

double a_double = double_matrix.submatrix( 1,1, 2,1);
```


Our matrix template offer the following operations:

``` c++

    E operator ()( int accessed_row, int accessed_column) const;

    E& operator ()(int accessed_row, int accessed_column);

    E getRowNumber() const;

    E getColumnNumber() const;

    shared_matrix <E> transpose() const;

    shared_matrix <E> diagonal() const;

    shared_matrix <E> submatrix(pair <int, int > first_pair, pair <int ,int > second_pair) const;

    const shared_matrix <E> diagonal_matrix() const;

    row_matrix_iterator <E> begin() const;

    row_matrix_iterator <E> end() const;
    
```

##DESIGN

In this section we explain the design 
###Decorator design pattern

Our matrix template has been designed with the decorator pattern. In particular we have implemented this pattern using the dynamic polymorphism offered by c++ :

* `matrix_impl` is the interface for the base matrix class and the decorator classes. 

* `base_matrix_impl` own the concrete data of the matrix. Has two integers r and c that represent row and column numbers, and a vector data, of type E, which contains the elements of the matrix. 

* `transposed_matrix_impl`
        the decoration class for the transposed matrix which has a pointer to the decorated matrix;
        it overrides the accessors calling the same methods to the decorated matrix with inverted input. 

* `diagonal_impl`
        the decoration class for the vector which contains the diagonal elements of the decorated matrix;
        it is a vector (a matrix with r rows and 1 column) accessing elements of the decorated matrix which are on diagonal positions; note that its rows are the minimum between rows and columns of the decorated matrix.
    
* `diagonal_matrix_impl`
        the decoration class for the unmodifyable matrix which returns 0's on non-diagonal positions;
        it must be used with the keyword ```const``` upon copy even if the keyword ```auto``` is used; otherwise the client risks to cause an "Unmodifyable matrix" error.
        We offered a type conversion for the zeroes of the diagonal**FIL**

* `submatrix_matrix_impl`
        a decoration of the matrix class, which has a shared pointer to the decorated matrix;
        it is a vector which accesses a portion of elements of the decorated matrix.
        its creator takes two pairs of ```<int>```s which refer to the positions of the first and last elements of the matrix;
        its default creator returns a decoration of the matrix with all the elements; it gives therefore no error, but it is not advisable to do so as it lengthen the chain of decorations;

###Shared pointers
In our design we decided to use smart ponters over raw pointers to manage lifetime of the objects, thus preventing memory leaks from unexpected behaviours from user's program.

Once we decided to use smart pointers we discussed the advantages / disadvantages between two possible implementations: `std::shared_ptr` and `std::unique_ptr`.

###PIMPL idiom
The PIMPL Idiom (Pointer to IMPLementation) is a technique for implementation hiding in which a public class wraps a structure or class that cannot be seen outside the library the public class is part of.

We adopted PIMPL to hide the management of the smart pointers inside the wrapper class `matrix` thus offering a better usability. 

###Iterators

The file iterator.h contains things. They do things in this way so that other things are done. **FIL**

Errors are const char *, thrown to inform the user about the type of errors. **FIL**

###Pros and cons

//Creare una matrice con un vettore è scomodo//
The use of a Decorator Design Pattern implies the possibility of a long chain of calls.
By using a matrix which uses predefinite zero conversions. This is a disadvantage for the use of types which are not predefinite, but it's easily fixable.
By using a ```diagonal_matrix()``` method without the use of the ```const``` keyword the user may throw error messages during a simple print.***FIL**

