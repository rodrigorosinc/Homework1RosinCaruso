/*
a. Crear una función que dado un valor entero “n”, positivo y mayor a uno, devuelva
una matriz cuadrada con valores como en los siguientes ejemplos para n=2 y n=3:
𝑀2 = [1 2 
      3 4] 
𝑀3 = [ 1 2 3
       4 5 6
       7 8 9]

b. Proveer un código que imprima el contenido de la matriz, utilizando un único ciclo
for, desde el mayor valor al menor, es decir, para el ejemplo de Para 𝑀2:
𝑀2[1][1] = 4
𝑀2[1][0] = 3
𝑀2[0][1] = 2
𝑀2[0][0] = 1
Nota: recuerde que se deben imprimir los índices de la matriz.   
*/

#include <iostream>
using namespace std;

int** matrix(size_t n){
    int count = 1;
    int** mat = new int*[n];
    if (!mat) return nullptr;
    for(size_t i = 0; i < n; i++){
        int* row = new int[n];
        if (!row){
            for (size_t k = 0; k<i; k++){
                delete [] mat[k];
            }
            delete mat;
            return nullptr;
        }
        for(size_t j = 0; j < n; j++){
            row[j] = count;
            count++;
        }
        mat[i] = row;
    }
    return mat;
}

void print_matrix(int** mat, int n){
    if (!mat) return;
    size_t iterations = n*n;
    int row = 0;
    int column = 0;
    for (size_t i = 0; i<iterations; i++){
        cout << "Matrix[" << row << "]" << "[" << column << "] = " << mat[row][column] << endl;
        column++;
        if (column == n){
            row++;
            column = 0;
        }
    }
    return;
}

void destroy_matrix(int** mat, int n){
    for (int i = 0; i<n; i++){
        delete[] mat[i];
    }
    delete[] mat;
    return;
}

int main(){
    size_t n;
    cout << "Ingrese un valor entero positivo y mayor a uno: ";
    cin >> n;
    int** mat = matrix(n);
    print_matrix(mat, n);
    destroy_matrix(mat, n);
    return 0;
}