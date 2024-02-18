#include <stdio.h>
#include <stdlib.h>

// Strassen's Matrix Multiplication function (implementation not provided here)
void strassen_multiply(int **A, int **B, int **C, int n) {
    // Implementation of Strassen's Matrix Multiplication goes here
    // This function is left as a placeholder
}

int main() {
    int n, i, j;

    printf("Enter the size of matrices: ");
    scanf("%d", &n);

    // Allocating memory for matrices
    int **A = (int **)malloc(n * sizeof(int *));
    int **B = (int **)malloc(n * sizeof(int *));
    int **C = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
        B[i] = (int *)malloc(n * sizeof(int));
        C[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Multiplying matrices using Strassen's algorithm
    strassen_multiply(A, B, C, n);

    // Displaying the result
    printf("Resultant matrix C:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Freeing memory
    for (i = 0; i < n; i++) {
        free(A[i]); free(B[i]); free(C[i]);
    }
    free(A); free(B); free(C);

    return 0;
}


//Not completed