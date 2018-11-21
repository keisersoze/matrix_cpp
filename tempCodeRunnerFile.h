int row_offset;
    int col_offset;


/**
* Declaration of submatrix
* @tparam E
* @tparam r
* @tparam c
*/
template <typename E, int r, int c>
class submatrix : public /* protected private */ base_matrix < E , c , r> { // by_arn: sicuro che può essere public? significa che può essere creata dall'utente. penso dovrebbe essere "protected" o "private". Consiglio di tenerla public e quando testiamo proviamo a cambiare l'impostazione.

private:
    base_matrix<E, r, c> *wrapped_matrix;
    int row_offset, col_offset;
public:

    submatrix(base_matrix<E, r, c> *matrix, int upper_row, int upper_col, int lower_row, int lower_col); // prende in input la wrapped base_matrix e la posizione del primo elemento e dell'ultimo elemento della sottomatrice.

    E operator()(int accessed_row, int accessed_column);
};


/**
 * Implementation of submatrix
 */
/*
template <typename E, int r, int c>
submatrix<E, r, c>::submatrix(base_matrix<E, r, c> *base_matrix, int upper_row, int upper_col){
    if (upper_row > lower_row || upper_col > lower_col || sub_r != lower_row - upper_row + 1 || sub_c != lower_col - upper_col + 1 ){
        // throw Bad_size();
    }else {
        wrapped_matrix = base_matrix;
        row_offset = upper_row -1;
        col_offset = upper_col -1;
    }
}

template<typename E, int r, int c>
E submatrix<E, r, c>::operator()(int accessed_row, int accessed_column) {
    return wrapped_matrix->at(accessed_row + row_offset, accessed_column + col_offset);
}
*/


/*
 * TODO codice di arn
 */

//inizio codice di arn
// ERRORE: cosa scrivo nel tipo di ritorno? deve ritornare una matrice <E, intero_non_conosciuto, intero_non_conosciuto >
//base_matrix< E, sub_r, sub_c >* submatrix(int upper_row, int upper_col, int lower_row, int lower_col); //by_arn
//fine codice di arn

//inizio codice di arn
/* cosa scrivo nel tipo di ritorno? deve ritornare una matrice di dimensione non conosciuta fino alla chiamata della funzione
base_matrix<E, sub_r, sub_c >* Matrix<E, r, c>::submatrix(int upper_row, int upper_col, int lower_row, int lower_col){
    return new submatrix< E, sub_r, sub_c>(this, upper_row, upper_col, lower_row, lower_col);
}   */
//fine codice di arn


template<typename E, int r, int c>
E base_matrix<E, r, c>::operator()(int accessed_row, int accessed_column) {
    return at(accessed_row,accessed_column);
}


template<typename E, int r, int c>


template<typename E, int r, int c>



template<typename E, int r, int c>
void base_matrix<E, r, c>::print() {
    array<int, c * r> array= *(matrix_ptr.get());
    for (int i = 0; i < c * r; ++i) {
        std::cout << array[i] << ' ';
    }
}
