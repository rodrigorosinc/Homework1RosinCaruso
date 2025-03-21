#include <iostream>
using namespace std;

int** matrix(size_t n){
    int count = 1;              //contador para llenar la matriz
    int** mat = new int*[n];    //asigno la memoria para las filas
    if (!mat) return nullptr;   //si no se pudo asignar memoria, retorno nullptr
    for(size_t i = 0; i < n; i++){
        int* row = new int[n];  //asigno la memoria para las columnas
        if (!row){              //chequeo que se haya asignado bien la memoria
            for (size_t k = 0; k<i; k++){ //si hubo error, libero la memoria de las filas anteriores tambien
                delete [] mat[k];
            } 
            delete mat;
            return nullptr;
        }
        for(size_t j = 0; j < n; j++){   //lleno la matriz
            row[j] = count;
            count++;
        }
        mat[i] = row;
    }
    return mat;
}

void print_matrix(int** mat, int n){
    if (!mat) return;
    size_t iterations = n*n;    //cantidad de elementos en la matriz
    int row = n-1;              //fila final para empezar a iterar la matriz
    int column = n-1;           //columna final para empezar a iterar la matriz
    for (size_t i = 0; i<iterations; i++){
        cout << "M[" << row << "][" << column << "] = " << mat[row][column] << endl;
        if (column == 0){       //si llegue al final de la fila, paso a la siguiente
            row--;
            column = n-1;
        } else {               //si no, sigo en la misma fila, pero paso a la columna anterior
            column--;
        }
    }
    return;
}

void destroy_matrix(int** mat, int n){
    for (int i = 0; i<n; i++){ //libero la memoria de las columnas
        delete[] mat[i];
    }
    delete[] mat;              //destruyo las filas
    return;
}

int main(){
    size_t n;
    cout << "Input n, for the matrix's size: ";
    cin >> n;
    int** mat = matrix(n);  // creo la matriz
    print_matrix(mat, n);   // imprimo la matriz
    destroy_matrix(mat, n); // libero la memoria
    return 0;
}