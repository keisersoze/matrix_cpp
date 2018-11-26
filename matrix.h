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

    matrix(shared_ptr < matrix_impl <E> > decorated_matrix_ptr):matrix_impl_ptr(decorated_matrix_ptr){}

public:

    matrix (const matrix & m){
        vector < E > v;
        auto b = m.begin();
        auto e = m.end();
        for (auto i = b; i != e ; ++i) {
            v.push_back(*i);
        }
        matrix_impl_ptr = make_shared <base_matrix_impl <E>> (v,m.getRowNumber(),m.getColumnNumber());
    }

    matrix(const vector<E> &data,const int &r, const int &c) {
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
        return matrix_temp <E> (move (make_shared <transposed_matrix_impl <E> >(matrix_impl_ptr)));
    }

    matrix_temp <E> diagonal() const {
        return matrix_temp <E> (move (make_shared <diagonal_impl <E> >(matrix_impl_ptr)));
    }


    matrix_temp <E> submatrix(pair <int, int > first_pair, pair <int ,int > second_pair) const{
        return matrix_temp <E> (move (make_shared <submatrix_matrix_impl <E> >(matrix_impl_ptr, first_pair, second_pair)));
    }

    matrix_temp <E> diagonal_matrix() const {
        return matrix_temp <E> (move (make_shared <diagonal_matrix_impl <E> >(matrix_impl_ptr)));
    }

    column_matrix_iterator <E> begin() const{
        return column_matrix_iterator <E> (matrix_impl_ptr, 1, 1);
    }

    column_matrix_iterator <E> end() const{
        return column_matrix_iterator <E> (matrix_impl_ptr, matrix_impl_ptr->getRowNumber()+1 , 1);
    }
};

template < typename E >
class matrix_temp : public matrix <E>  {

public:
    matrix_temp(shared_ptr<matrix_impl<E>> decorated_matrix_ptr) : matrix <E> (decorated_matrix_ptr) {}

    matrix_temp (const matrix_temp & m) : matrix <E> (m.matrix_impl_ptr) {}
};

/* UTILS FUNCTIONS */

string prettyprint (const matrix<int> & m){
    string out("");
    for (int i = 1 ; i <= m.getRowNumber() ; ++i) {
        for (int j = 1 ; j <= m.getColumnNumber() ; ++j) {
            out += to_string(m(i,j)) + " ";
        }
        out += "\n";
    }
    return out + "\n";
}

