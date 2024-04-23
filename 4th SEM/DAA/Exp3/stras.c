#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 128

// Function to multiply two matrices using the normal method
void normalMatrixMultiplication(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to add two matrices
void add(int n, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract(int n, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to perform Strassen's matrix multiplication
void strassenMatrixMultiplication(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int n) {
    if (n <= 64) {
        normalMatrixMultiplication(A, B, C, n);
        return;
    }

    int i, j;
    int newSize = n / 2;
    int A11[MAX_SIZE][MAX_SIZE], A12[MAX_SIZE][MAX_SIZE], A21[MAX_SIZE][MAX_SIZE], A22[MAX_SIZE][MAX_SIZE];
    int B11[MAX_SIZE][MAX_SIZE], B12[MAX_SIZE][MAX_SIZE], B21[MAX_SIZE][MAX_SIZE], B22[MAX_SIZE][MAX_SIZE];
    int C11[MAX_SIZE][MAX_SIZE], C12[MAX_SIZE][MAX_SIZE], C21[MAX_SIZE][MAX_SIZE], C22[MAX_SIZE][MAX_SIZE];
    int P1[MAX_SIZE][MAX_SIZE], P2[MAX_SIZE][MAX_SIZE], P3[MAX_SIZE][MAX_SIZE], P4[MAX_SIZE][MAX_SIZE];
    int P5[MAX_SIZE][MAX_SIZE], P6[MAX_SIZE][MAX_SIZE], P7[MAX_SIZE][MAX_SIZE];
    int temp1[MAX_SIZE][MAX_SIZE], temp2[MAX_SIZE][MAX_SIZE];

    // Divide matrices A and B into submatrices
    for (i = 0; i < newSize; i++) {
        for (j = 0; j < newSize; j++) {
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

    // Compute seven products of Strassen's algorithm
    subtract(newSize, B12, B22, temp1);
    strassenMatrixMultiplication(A11, temp1, P1, newSize);

    add(newSize, A11, A12, temp1);
    strassenMatrixMultiplication(temp1, B22, P2, newSize);

    add(newSize, A21, A22, temp1);
    strassenMatrixMultiplication(temp1, B11, P3, newSize);

    subtract(newSize, B21, B11, temp1);
    strassenMatrixMultiplication(A22, temp1, P4, newSize);

    add(newSize, A11, A22, temp1);
    add(newSize, B11, B22, temp2);
    strassenMatrixMultiplication(temp1, temp2, P5, newSize);

    subtract(newSize, A12, A22, temp1);
    add(newSize, B21, B22, temp2);
    strassenMatrixMultiplication(temp1, temp2, P6, newSize);

    subtract(newSize, A21, A11, temp1);
    add(newSize, B11, B12, temp2);
    strassenMatrixMultiplication(temp1, temp2, P7, newSize);

    // Compute the resulting submatrices
    add(newSize, P5, P4, temp1);
    subtract(newSize, temp1, P2, temp2);
    add(newSize, temp2, P6, C11);

    add(newSize, P1, P2, C12);

    add(newSize, P3, P4, C21);

    add(newSize, P5, P1, temp1);
    subtract(newSize, temp1, P3, temp2);
    subtract(newSize, temp2, P7, C22);

    // Combine the resulting submatrices into the final matrix
    for (i = 0; i < newSize; i++) {
        for (j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

// Function to generate random matrix
void generateRandomMatrix(int A[MAX_SIZE][MAX_SIZE], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = rand() % 100; // generate random number between 0 and 99
        }
    }
}

// Function to measure time elapsed
double time_elapsed(struct timespec start, struct timespec end) {
    return (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    struct timespec start, end;
    double time_normal, time_strassen;
    int n, i, j;

    FILE *fptr;
    fptr = fopen("matrix_multiplication.csv", "w");
    if (!fptr) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fptr, "Matrix Size,     Normal Multiplication Time(s),     Strassen Multiplication Time(s)\n");

    for (n = 2; n <= MAX_SIZE; n *= 2) {
        generateRandomMatrix(A, n);
        generateRandomMatrix(B, n);

        clock_gettime(CLOCK_MONOTONIC, &start);
        normalMatrixMultiplication(A, B, C, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        time_normal = time_elapsed(start, end);

        clock_gettime(CLOCK_MONOTONIC, &start);
        strassenMatrixMultiplication(A, B, C, n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        time_strassen = time_elapsed(start, end);

        printf("Matrix Size: %d,       Normal Multiplication Time: %f seconds,            Strassen Multiplication Time: %f seconds\n", n, time_normal, time_strassen);
        fprintf(fptr, "%d,%f,%f\n", n, time_normal, time_strassen);
    }

    fclose(fptr);

    return 0;
}

