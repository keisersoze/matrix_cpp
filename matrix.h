//
// Filippo Maganza and Arnaldo xxx
//

#include "matrix_impl.h"

template < typename E>
class matrix_temp;

template < typename E>
class matrix {

private:

    shared_ptr < matrix_impl <E> > shared_ptr1;

protected:

    matrix(shared_ptr < matrix_impl <E> > decorated_matrix_ptr):shared_ptr1(move(decorated_matrix_ptr)){
    }

public:

    matrix(const vector<E> &data,const int &r, const int &c) {
        shared_ptr1 = make_shared <base_matrix_impl <E>> (data,r,c);
    }

    E get(int accessed_row, int accessed_column){
        return shared_ptr1->get(accessed_row,accessed_column);
    }

    //se torniamo per valore chiama il copy costructor di matrix che fa la deep copy ed è una cosa che non vogliamo, così ho creato il tipo matrix_temp
    matrix_temp <E> transpose(){
        return matrix_temp <E> (move (make_shared <transposed_matrix_impl <E> >(shared_ptr1)));
    }

    matrix_temp <E> diagonal(){
        return matrix_temp <E> (move (make_shared <diagonal_matrix_impl <E> >(shared_ptr1)));
    }

};

template < typename E>
class matrix_temp : public matrix <E>  {

public:
    matrix_temp(shared_ptr<matrix_impl<E>> decorated_matrix_ptr) : matrix <E> (move(decorated_matrix_ptr)) {}

};

