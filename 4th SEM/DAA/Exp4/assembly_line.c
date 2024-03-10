#include <stdio.h>

#define NUM_STATIONS 5
#define NUM_LINES 2

int min(int a, int b) {
    return (a < b) ? a : b;
}

int productAssembly(int a[][NUM_STATIONS], int t[][NUM_STATIONS - 1], int e[2], int x[2]) {
    int f1[NUM_STATIONS], f2[NUM_STATIONS];

    // Time taken to reach the first station at line 1
    f1[0] = e[0] + a[0][0];

    // Time taken to reach the first station at line 2
    f2[0] = e[1] + a[1][0];

    // Fill tables f1[] and f2[] using the given recursive relations
    for (int j = 1; j < NUM_STATIONS; j++) {
        f1[j] = min(f1[j - 1] + a[0][j], f2[j - 1] + t[1][j - 1] + a[0][j]);
        f2[j] = min(f2[j - 1] + a[1][j], f1[j - 1] + t[0][j - 1] + a[1][j]);
    }

    // Display the table of line and cost for each line
    printf("\nLine and Cost Table:\n");
    printf("Station  Line 1 Cost  Line 2 Cost\n");

    for (int i = 0; i < NUM_STATIONS; i++) {
        printf("%8d %12d %12d\n", i + 1, f1[i], f2[i]);
    }

    // Consider exit times and return minimum
    return min(f1[NUM_STATIONS - 1] + x[0], f2[NUM_STATIONS - 1] + x[1]);
}

int main() {
    int a[NUM_LINES][NUM_STATIONS] = {{8, 10, 4, 5, 9}, {9, 6, 7, 5, 6}};
    int t[NUM_LINES][NUM_STATIONS - 1] = {{2, 3, 1, 3}, {2, 1, 2, 2}};
    int e[NUM_LINES] = {3, 5};
    int x[NUM_LINES] = {2, 1};

    // Calculate and display the optimal time for completing the product
    int optimalTime = productAssembly(a, t, e, x);
    printf("\nOptimal Time for completing the product is: %d\n", optimalTime);

    return 0;
}