#include <stdio.h>

#define NUM_STATIONS 5
#define NUM_LINES 2

int min(int a, int b) {
    return (a < b) ? a : b;
}

int productAssembly(int a[][NUM_STATIONS], int t[][NUM_STATIONS - 1], int e[2], int x[2]) {
    int f1[NUM_STATIONS], f2[NUM_STATIONS];
    int line[NUM_STATIONS];  // Keep track of the line with minimum time
    int stationPath[NUM_STATIONS]; // Keep track of selected stations

    // Time taken to reach the first station at line 1
    f1[0] = e[0] + a[0][0];

    // Time taken to reach the first station at line 2
    f2[0] = e[1] + a[1][0];

    // Fill tables f1[] and f2[] using the given recursive relations
    for (int j = 1; j < NUM_STATIONS; j++) {
        if (f1[j - 1] + a[0][j] <= f2[j - 1] + t[1][j - 1] + a[0][j]) {
            f1[j] = f1[j - 1] + a[0][j];
            line[j] = 1;
        } else {
            f1[j] = f2[j - 1] + t[1][j - 1] + a[0][j];
            line[j] = 2;
        }

        if (f2[j - 1] + a[1][j] <= f1[j - 1] + t[0][j - 1] + a[1][j]) {
            f2[j] = f2[j - 1] + a[1][j];
            line[j] = 2;
        } else {
            f2[j] = f1[j - 1] + t[0][j - 1] + a[1][j];
            line[j] = 1;
        }
    }

    // Add exit times for each line
    int optimalTime = min(f1[NUM_STATIONS - 1] + x[0], f2[NUM_STATIONS - 1] + x[1]);

    // Trace the path
    int exitLine = (f1[NUM_STATIONS - 1] + x[0] < f2[NUM_STATIONS - 1] + x[1]) ? 1 : 2;
    stationPath[NUM_STATIONS - 1] = exitLine;

    for (int j = NUM_STATIONS - 1; j > 0; j--) {
        if (exitLine == 1) {
            exitLine = line[j];
        } else {
            exitLine = (line[j] == 1) ? 2 : 1;
        }
        stationPath[j - 1] = exitLine;
    }

    // Display the table of line and cost for each line
    printf("\nLine and Cost Table:\n");
    printf("Station  Line 1 Cost  Line 2 Cost\n");

    for (int i = 0; i < NUM_STATIONS; i++) {
        printf("%8d %12d %12d\n", i + 1, f1[i], f2[i]);
    }

    // Display the path
    printf("\nSelected Path:\n");
    printf("Line    Station\n");
    for (int i = 0; i < NUM_STATIONS; i++) {
        printf("%4d %9d\n", stationPath[i], i + 1);
    }

    printf("\nOutput is exiting from Line %d\n", stationPath[NUM_STATIONS - 1]);

    return optimalTime;
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





    // int a[NUM_LINES][NUM_STATIONS], t[NUM_LINES][NUM_STATIONS - 1], e[NUM_LINES], x[NUM_LINES];

    // printf("Enter values for a:\n");
    // for (int i = 0; i < NUM_LINES; i++) {
    //     printf("Line %d: ", i + 1);
    //     for (int j = 0; j < NUM_STATIONS; j++) {
    //         scanf("%d", &a[i][j]);
    //     }
    // }

    // printf("Enter values for t:\n");
    // for (int i = 0; i < NUM_LINES; i++) {
    //     printf("Line %d: ", i + 1);
    //     for (int j = 0; j < NUM_STATIONS - 1; j++) {
    //         scanf("%d", &t[i][j]);
    //     }
    // }

    // printf("Enter values for e:\n");
    // for (int i = 0; i < NUM_LINES; i++) {
    //     printf("", i + 1);
    //     scanf("%d", &e[i]);
    // }

    // printf("Enter values for x:\n");
    // for (int i = 0; i < NUM_LINES; i++) {
    //     printf("", i + 1);
    //     scanf("%d", &x[i]);
    // }

    // int optimalTime = productAssembly(a, t, e, x);
    // printf("\nOptimal Time for completing the product is: %d\n", optimalTime);

    // return 0;
}