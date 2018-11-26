//
// Filippo Maganza and Arnaldo Santoro
//

#include "iterator.h"

/* WRAPPERS */

template < typename E>
class matrix_temp;

template < typename E >
class matrix {

private:

    shared_ptr < matrix_impl <E> > shared_ptr1;

protected:

    matrix(shared_ptr < matrix_impl <E> > decorated_matrix_ptr):shared_ptr1(move(decorated_matrix_ptr)){
    }

public:

    /*
    matrix (const matrix & m){
        vector < E > v;
        auto b = m.begin();
        auto e = m.end();
        for (auto i = b; i != e ; ++i) {
            v.push_back(*i);
        }
        v.push_back(*(m.end()));
        shared_ptr1 = make_shared <base_matrix_impl <E>> (v,m.getRowNumber(),m.getColumnNumber());
    }*/


    matrix(const vector<E> &data,const int &r, const int &c) {
        shared_ptr1 = make_shared <base_matrix_impl <E>> (data,r,c);
    }

    E operator ()(int accessed_row, int accessed_column) const{
        return shared_ptr1->get(accessed_row,accessed_column);
    }

    /*E& set (int accessed_row, int accessed_column) {
        return shared_ptr1->get(accessed_row,accessed_column);
    }*/

    void set(int accessed_row, int accessed_column, E new_elem) {
        shared_ptr1->set(accessed_row,accessed_column, new_elem);
    }

    E getRowNumber() const{
        return shared_ptr1->getRowNumber();
    }

    E getColumnNumber() const{
        return shared_ptr1->getColumnNumber();
    }

    //se torniamo per valore chiama il copy costructor di matrix che fa la deep copy ed è una cosa che non vogliamo, così ho creato il tipo matrix_temp
    matrix_temp <E> transpose() const {
        return matrix_temp <E> (move (make_shared <transposed_matrix_impl <E> >(shared_ptr1)));
    }

    matrix_temp <E> diagonal() const {
        return matrix_temp <E> (move (make_shared <diagonal_matrix_impl <E> >(shared_ptr1)));
    }


    matrix_temp <E> submatrix(pair <int, int > first_pair, pair <int ,int > second_pair) const{
        return matrix_temp <E> (move (make_shared <submatrix_matrix_impl <E> >(shared_ptr1, first_pair, second_pair)));
    }

    column_matrix_iterator <E> begin() const{
        return column_matrix_iterator <E> (shared_ptr1, 1, 1);
    }

    column_matrix_iterator <E> end() const{
        return column_matrix_iterator <E> (shared_ptr1, shared_ptr1->getRowNumber(), shared_ptr1->getRowNumber());
    }
};

template < typename E >
class matrix_temp : public matrix <E>  {

public:
    matrix_temp(shared_ptr<matrix_impl<E>> decorated_matrix_ptr) : matrix <E> (move(decorated_matrix_ptr)) {}



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
    return out;
}

