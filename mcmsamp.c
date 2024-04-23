#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define NUM_MATRICES 10

// Function to allocate memory for a 2D matrix
int** allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free memory for a 2D matrix
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to perform Matrix Chain Multiplication using dynamic programming
void matrixChainMultiplication(int dims[], int n, int **m, int **c) {
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k+1][j] + dims[i-1]*dims[k]*dims[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    c[i][j] = k;
                }
            }
        }
    }
}

int main() {
    // Hardcoded dimensions for matrices
    int dims[NUM_MATRICES + 1] = {15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 46}; // Dimensions of matrices M0 to M10

    // Allocate memory for storing optimal solutions and parenthesizations
    int **m = allocateMatrix(NUM_MATRICES + 1, NUM_MATRICES + 1);
    int **c = allocateMatrix(NUM_MATRICES + 1, NUM_MATRICES + 1);

    // Perform Matrix Chain Multiplication and measure time
    clock_t start = clock();
    matrixChainMultiplication(dims, NUM_MATRICES, m, c);
    clock_t end = clock();
    double duration_mcm = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print optimal solutions
    printf("\nOptimal Solutions (No. of Multiplications):\n");
    for (int i = 1; i <= NUM_MATRICES; i++) {
        for (int j = 1; j <= NUM_MATRICES; j++) {
            printf("%6d", m[i][j]);
        }
        printf("\n");
    }

    // Print time for Matrix Chain Multiplication
    printf("\nTime for Matrix Chain Multiplication: %.6f seconds\n", duration_mcm);

    // Print the cost matrix and the k matrix
    printf("\nCost Matrix:\n");
    for (int i = 1; i <= NUM_MATRICES; i++) {
        for (int j = 1; j <= NUM_MATRICES; j++) {
            printf("%6d", m[i][j]);
        }
        printf("\n");
    }
    
    printf("\nK Matrix:\n");
    for (int i = 1; i <= NUM_MATRICES; i++) {
        for (int j = 1; j <= NUM_MATRICES; j++) {
            printf("%6d", c[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory for optimal solutions and parenthesizations
    freeMatrix(m, NUM_MATRICES + 1);
    freeMatrix(c, NUM_MATRICES + 1);

    return 0;
}
