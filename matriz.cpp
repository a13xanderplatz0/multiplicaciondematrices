#include <iostream>
using namespace std;

// Función para multiplicar dos matrices 3x3 usando aritmética de punteros
void mult(int (*p)[3], int (*q)[3], int (*r)[3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(*(r + i) + j) = 0; // Inicializar el elemento de la matriz resultado
            for (int k = 0; k < 3; k++) {
                *(*(r + i) + j) += *(*(p + i) + k) * *(*(q + k) + j);
            }
        }
    }
}

// Función para imprimir una matriz 3x3
void printMatrix(int (*p)[3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << *(*(p + i) + j) << " ";
        }
        cout << endl;
    }
}

int main() {
    // Definir dos matrices 3x3
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C[3][3]; // Matriz resultado

    // Llamar a la función de multiplicación
    mult(A, B, C);

    // Imprimir matrices
    cout << "Matriz A:" << endl;
    printMatrix(A);
    cout << "Matriz B:" << endl;
    printMatrix(B);
    cout << "Matriz Resultado (A * B):" << endl;
    printMatrix(C);

    return 0;
}