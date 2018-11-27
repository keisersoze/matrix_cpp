//
// Filippo Maganza and Arnaldo Santoro
//

#include "iterator.h"

/* WRAPPERS */

template < typename E>
class matrix_temp;

template < typename E >
class matrix {

protected:

    shared_ptr < matrix_impl <E> > matrix_impl_ptr;

public:

    matrix() {}

    matrix (const matrix & m){
        vector < E > v;
        for (auto i = m.begin(); i != m.end() ; ++i) {
            v.push_back(*i);
        }
        matrix_impl_ptr = make_shared <base_matrix_impl <E>> (v,m.getRowNumber(),m.getColumnNumber());
    }

    matrix(const vector<E> &data, int r, int c) {
        matrix_impl_ptr = make_shared <base_matrix_impl <E>> (data,r,c);
    }


    E operator ()(int accessed_row, int accessed_column) const{
        return matrix_impl_ptr->get(accessed_row,accessed_column);
    }

    E& operator ()(int accessed_row, int accessed_column) {
        return matrix_impl_ptr->get_ref(accessed_row,accessed_column);
    }


    E getRowNumber() const{
        return matrix_impl_ptr->getRowNumber();
    }

    E getColumnNumber() const{
        return matrix_impl_ptr->getColumnNumber();
    }


    matrix_temp <E> transpose() const {
        return matrix_temp <E> (make_shared <transposed_matrix_impl <E> >(matrix_impl_ptr));
    }

    matrix_temp <E> diagonal() const {
        return matrix_temp <E> (make_shared <diagonal_impl <E> >(matrix_impl_ptr));
    }

    matrix_temp <E> submatrix(pair <int, int > first_pair, pair <int ,int > second_pair) const{
        return matrix_temp <E> (make_shared <submatrix_matrix_impl <E> >(matrix_impl_ptr, first_pair, second_pair));
    }

    matrix_temp <E> submatrix(int first_row, int first_col, int last_row, int last_col) const{
        return matrix_temp <E> (make_shared <submatrix_matrix_impl <E> >(matrix_impl_ptr, first_row, first_col, last_row, last_col));
    }

    const matrix_temp <E> diagonal_matrix() const {
        return matrix_temp <E> (make_shared <diagonal_matrix_impl <E> >(matrix_impl_ptr));
    }


    row_matrix_iterator <E> begin() const{
        return row_matrix_iterator <E> (matrix_impl_ptr, 1, 1);
    }

    row_matrix_iterator <E> end() const{
        return row_matrix_iterator <E> (matrix_impl_ptr, matrix_impl_ptr->getRowNumber()+1 , 1);
    }

    column_matrix_iterator <E> begin_column() const{
        return column_matrix_iterator <E> (matrix_impl_ptr, 1, 1);
    }

    column_matrix_iterator <E> end_column() const{
        return column_matrix_iterator <E> (matrix_impl_ptr, 1 , matrix_impl_ptr->getColumnNumber()+1);
    }

};

template < typename E >
class matrix_temp : public matrix <E>  {

public:

    matrix_temp(shared_ptr<matrix_impl<E>> decorated_matrix_ptr){
        this->matrix_impl_ptr = move (decorated_matrix_ptr);
    }

    matrix_temp (const matrix_temp & m) {
        this->matrix_impl_ptr = m.matrix_impl_ptr;
    }

};


/* UTILS FUNCTIONS */
template < typename E >
string prettyprint (const matrix<E> & m){
    string out("");
    for (int i = 1 ; i <= m.getRowNumber() ; ++i) {
        for (int j = 1 ; j <= m.getColumnNumber() ; ++j) {
            out += to_string(m(i,j)) + " ";
        }
        out += "\n";
    }
    return out + "\n";
}

template <typename E>
void print_row_col(const matrix<E>& matrix){
    cout<<"this matrix's row and column numbers are "<<matrix.getRowNumber()<<" and "<<matrix.getColumnNumber()<<endl<<endl;
}

