//
// Filippo Maganza and Arnaldo Santoro
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
/*
    matrix_temp <E> submatrix(){
        
        // il costruttore standard di una sottomatrice ritorna una "sottomatrice" identica alla matrice di partenza
        //sicuramente inutile, potenzialmente rimuovibile...? L'ho inserito per avere un costruttore standard per la sottomatrice.
        
        return this.submatrix(1, 1, getRowNumber, getColumnNumber)
    }
    matrix_temp <E> submatrix(int upper_row, int upper_column, int lower_row, int lower_column){
        
        // l'input valido per la matrice è due coppie di interi:
        // la prima coppia di valori indica riga e colonna del primo elemento della sottomatrice
        // la seconda coppia di valori indica riga e colonna dell'ultimo elemento della sottomatrice
        // l'input non è valido se la prima coppia "supera" la seconda coppia o se gli input non sono validi (input < 1 o input > getRowNumber o getColumnNumber) 
        
        if (upper_row < 1 || upper_column < 1 || lower_row < 1 || lower_column < 1 ||
            lower_row > getRowNumber() || lower_column > getColumnNumber() || upper_row > lower_row || upper_column > lower_column){
            throw "Invalid submatrix input."
            }
        else
        {
            // deve impostare i parametri della sottomatrice
            row_offset = upper_row - 1;
            column_offset = upper_column - 1;
            sub_r = lower_row - upper_row + 1;
            sub_c = lower_column - upper_column + 1;
            return matrix_temp <E> (move (make_shared <submatrix_matrix_impl <E> >(shared_ptr1))); )) 
        }
    }
*/
};

template < typename E>
class matrix_temp : public matrix <E>  {

public:
    matrix_temp(shared_ptr<matrix_impl<E>> decorated_matrix_ptr) : matrix <E> (move(decorated_matrix_ptr)) {}

};

