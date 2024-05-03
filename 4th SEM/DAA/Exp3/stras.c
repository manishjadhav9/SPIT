#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 2

// Function to multiply two matrices using the normal method
void normalMatrixMultiplication(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int n) {
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
}

// Function to perform Strassen's matrix multiplication
void strassenMatrixMultiplication(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int n) {
    int P1, P2, P3, P4, P5, P6, P7;

    P1 = A[0][0] * (B[0][1] - B[1][1]);
    P2 = (A[0][0] + A[0][1]) * B[1][1];
    P3 = (A[1][0] + A[1][1]) * B[0][0];
    P4 = A[1][1] * (B[1][0] - B[0][0]);
    P5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    P6 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
    P7 = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);

    C[0][0] = P5 + P4 - P2 + P6;
    C[0][1] = P1 + P2;
    C[1][0] = P3 + P4;
    C[1][1] = P5 + P1 - P3 - P7;
}

// Function to generate random 2x2 matrix
void generateRandomMatrix(int A[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            A[i][j] = rand() % 10; // generate random number between 0 and 9
        }
    }
}

// Function to print a 2x2 matrix
void printMatrix(int A[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];

    srand(time(NULL)); 

    printf("Matrix A:\n");
    generateRandomMatrix(A);
    printMatrix(A);
    printf("Matrix B:\n");
    generateRandomMatrix(B);
    printMatrix(B);

    normalMatrixMultiplication(A, B, C, MAX_SIZE);
    printf("Result of Normal Matrix Multiplication:\n");
    printMatrix(C);

    strassenMatrixMultiplication(A, B, C, MAX_SIZE);
    printf("Result of Strassen's Matrix Multiplication:\n");
    printMatrix(C);

    return 0;
}
