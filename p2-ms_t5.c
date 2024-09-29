#include <stdio.h>
#include <stdlib.h>

#define MAX 128

void sumarMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void restarMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int newSize = size / 2;
    if (newSize < 1) return;
    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];
    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX], M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];
    int temp1[MAX][MAX], temp2[MAX][MAX];
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
    sumarMatrices(A11, A22, temp1, newSize);
    sumarMatrices(B11, B22, temp2, newSize);
    strassen(temp1, temp2, M1, newSize);
    sumarMatrices(A21, A22, temp1, newSize);
    strassen(temp1, B11, M2, newSize);
    restarMatrices(B12, B22, temp1, newSize);
    strassen(A11, temp1, M3, newSize);
    restarMatrices(B21, B11, temp1, newSize);
    strassen(A22, temp1, M4, newSize);
    sumarMatrices(A11, A12, temp1, newSize);
    strassen(temp1, B22, M5, newSize);
    restarMatrices(A21, A11, temp1, newSize);
    sumarMatrices(B11, B12, temp2, newSize);
    strassen(temp1, temp2, M6, newSize);
    restarMatrices(A12, A22, temp1, newSize);
    sumarMatrices(B21, B22, temp2, newSize);
    strassen(temp1, temp2, M7, newSize);
    sumarMatrices(M1, M4, temp1, newSize);
    restarMatrices(temp1, M5, temp2, newSize);
    sumarMatrices(temp2, M7, C11, newSize);
    sumarMatrices(M3, M5, C12, newSize);
    sumarMatrices(M2, M4, C21, newSize);
    restarMatrices(M1, M2, temp1, newSize);
    sumarMatrices(temp1, M3, temp2, newSize);
    sumarMatrices(temp2, M6, C22, newSize);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main() {
    int size = 4;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
            C[i][j] = 0;
        }
    }
    strassen(A, B, C, size);
    printf("Matriz C:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}