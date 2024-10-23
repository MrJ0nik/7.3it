#include <iostream>
#include <iomanip>
using namespace std;

void CyclicShiftMatrix(int** matrix, int n, int k);
int FindLastColumnWithMaxZeros(int** matrix, int n);
void InputMatrix(int** matrix, int n);
void PrintMatrix(int** matrix, int n);

int main() {
    int n, k;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;
    cout << "Enter the number of positions to shift (k): ";
    cin >> k;

    
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    
    InputMatrix(matrix, n);

   
    cout << "Original matrix:" << endl;
    PrintMatrix(matrix, n);

   
    CyclicShiftMatrix(matrix, n, k);

    
    cout << "Matrix after cyclic shift by " << k << " positions:" << endl;
    PrintMatrix(matrix, n);

   
    int lastColWithMaxZeros = FindLastColumnWithMaxZeros(matrix, n);
    cout << "The last column with the maximum number of zeros is: " << lastColWithMaxZeros << endl;

    
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

void InputMatrix(int** matrix, int n) {
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
}

void PrintMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

void CyclicShiftMatrix(int** matrix, int n, int k) {
    for (int shift = 0; shift < k; shift++) {
        int temp = matrix[0][0];
        int i = 0, j = 0;

        
        for (i = 0; i < n - 1; i++) {
            matrix[i][j] = matrix[i + 1][j];
        }

        
        for (j = 0; j < n - 1; j++) {
            matrix[i][j] = matrix[i][j + 1];
        }

        
        for (i = n - 1; i > 0; i--) {
            matrix[i][n - 1] = matrix[i - 1][n - 1];
        }

        
        for (j = n - 1; j > 0; j--) {
            matrix[0][j] = matrix[0][j - 1];
        }

        matrix[0][1] = temp;  
    }
}

int FindLastColumnWithMaxZeros(int** matrix, int n) {
    int maxZeroCount = 0;
    int lastColWithMaxZeros = -1;

    for (int j = 0; j < n; j++) {
        int zeroCount = 0;
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
        if (zeroCount >= maxZeroCount) {
            maxZeroCount = zeroCount;
            lastColWithMaxZeros = j;
        }
    }

    return lastColWithMaxZeros;
}
