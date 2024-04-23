//ASSEMBLY LINE SCHEDULING USER INPUT
// #include <stdio.h>

// #define NUM_STATIONS 5
// #define NUM_LINES 2

// int min(int a, int b) {
//     return (a < b) ? a : b;
// }

// int productAssembly(int a[][NUM_STATIONS], int t[][NUM_STATIONS - 1], int e[2], int x[2]) {
//     int f1[NUM_STATIONS], f2[NUM_STATIONS];

//     // Time taken to reach the first station at line 1
//     f1[0] = e[0] + a[0][0];

//     // Time taken to reach the first station at line 2
//     f2[0] = e[1] + a[1][0];

//     // Fill tables f1[] and f2[] using the given recursive relations
//     for (int j = 1; j < NUM_STATIONS; j++) {
//         f1[j] = min(f1[j - 1] + a[0][j], f2[j - 1] + t[1][j - 1] + a[0][j]);
//         f2[j] = min(f2[j - 1] + a[1][j], f1[j - 1] + t[0][j - 1] + a[1][j]);
//     }

//     // Display the table of line and cost for each line
//     printf("\nLine and Cost Table:\n");
//     printf("Station  Line 1 Cost  Line 2 Cost\n");

//     for (int i = 0; i < NUM_STATIONS; i++) {
//         printf("%8d %12d %12d\n", i + 1, f1[i], f2[i]);
//     }

//     // Consider exit times and return minimum
//     return min(f1[NUM_STATIONS - 1] + x[0], f2[NUM_STATIONS - 1] + x[1]);
// }

// int main() {

//     int a[NUM_LINES][NUM_STATIONS], t[NUM_LINES][NUM_STATIONS - 1], e[NUM_LINES], x[NUM_LINES];

//     // Input values for a
//     printf("Enter values for a:\n");
//     for (int i = 0; i < NUM_LINES; i++) {
//         printf("Line %d: ", i + 1);
//         for (int j = 0; j < NUM_STATIONS; j++) {
//             scanf("%d", &a[i][j]);
//         }
//     }

//     // Input values for t
//     printf("Enter values for t:\n");
//     for (int i = 0; i < NUM_LINES; i++) {
//         printf("Line %d: ", i + 1);
//         for (int j = 0; j < NUM_STATIONS - 1; j++) {
//             scanf("%d", &t[i][j]);
//         }
//     }

//     // Input values for e
//     printf("Enter values for e:\n");
//     for (int i = 0; i < NUM_LINES; i++) {
//         printf("", i + 1);
//         scanf("%d", &e[i]);
//     }

//     // Input values for x
//     printf("Enter values for x:\n");
//     for (int i = 0; i < NUM_LINES; i++) {
//         printf("", i + 1);
//         scanf("%d", &x[i]);
//     }

//     // Calculate and display the optimal time for completing the product
//     int optimalTime = productAssembly(a, t, e, x);
//     printf("\nOptimal Time for completing the product is: %d\n", optimalTime);

//     return 0;
// }








//LCS HARD CODE
#include <stdio.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b)
{
  return (a > b) ? a : b;
}

// Function to find the length of longest common subsequence
// and print one of the common subsequences
void lcs(char *X, char *Y, int m, int n)
{
  int L[m + 1][n + 1];
  int i, j;

  // Building the L[m+1][n+1] in bottom-up fashion
  for (i = 0; i <= m; i++)
  {
    for (j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0)
        L[i][j] = 0;
      else if (X[i - 1] == Y[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;
      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
    }
  }

  // Following code is used to print one of the common subsequence
  int index = L[m][n];
  char lcs[index + 1];
  lcs[index] = '\0';

  // Start from the right-most-bottom-most corner and
  // one by one store characters in lcs[]
  i = m;
  j = n;
  while (i > 0 && j > 0)
  {
    // If current character in X[] and Y are same, then
    // current character is part of LCS
    if (X[i - 1] == Y[j - 1])
    {
      lcs[index - 1] = X[i - 1]; // Put current character in result
      i--;
      j--;
      index--; // reduce values of i, j and index
    }
    // If not same, then find the larger of two and
    // go in the direction of larger value
    else if (L[i - 1][j] > L[i][j - 1])
      i--;
    else
      j--;
  }

  // Print the lcs
  printf("Longest Common Subsequence: %s\n", lcs);
}

int main()
{
   char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  int m = strlen(X);
  int n = strlen(Y);
  lcs(X, Y, m, n);
  return 0;
}




//MIN-MAX HARD CODED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 100000
// #define ARRAY_SIZE 10
// Function prototypes
void generateNumbers(int numbers[], int size);
void minMaxDivideConquer(int numbers[], int start, int end, int *min, int *max);
void minMaxNaive(int numbers[], int size, int *min, int *max);
int main()
{
    FILE *p = fopen("minmax.csv", "w");
    fprintf(p, "Number, Time (Divide & Conquer), Time (Naive), Min, Max\n");

     //Hard-coded array with 10 values
    int numbers[ARRAY_SIZE] = {54, 21, 87, 63, 91, 37, 20, 48, 66, 15};

    int min_dc, max_dc, min_naive, max_naive;
    printf("Number, Time (Divide & Conquer), Time (Naive), Min, Max\n");
    for (int i = 10; i <= ARRAY_SIZE; i += 10)
    {
        clock_t start, end;

        // Divide and Conquer
        start = clock();
        minMaxDivideConquer(numbers, 0, i - 1, &min_dc, &max_dc);
        end = clock();
        double time_dc = ((double)(end - start)) / CLOCKS_PER_SEC;
        // Naive Approach
        start = clock();
        minMaxNaive(numbers, i, &min_naive, &max_naive);
        end = clock();
        double time_naive = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%d, %lf, %lf, %d, %d\n", i, time_dc, time_naive, min_dc, max_dc);
        fprintf(p, "%d, %lf, %lf, %d, %d\n", i, time_dc, time_naive, min_dc, max_dc);
    }
    return 0;
}
void generateNumbers(int numbers[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        numbers[i] = rand(); // Using rand() for simplicity
    }
}
void minMaxDivideConquer(int numbers[], int start, int end, int *min, int *max)
{
    if (start == end)
    {
        *min = *max = numbers[start];
        return;
    }
    int mid = (start + end) / 2;
    int min_left, max_left, min_right, max_right;
    minMaxDivideConquer(numbers, start, mid, &min_left, &max_left);
    minMaxDivideConquer(numbers, mid + 1, end, &min_right, &max_right);
    *min = (min_left < min_right) ? min_left : min_right;
    *max = (max_left > max_right) ? max_left : max_right;
}
void minMaxNaive(int numbers[], int size, int *min, int *max)
{
    *min = *max = numbers[0];
    for (int i = 1; i < size; ++i)
    {
        if (numbers[i] < *min)
        {
            *min = numbers[i];
        }
        else if (numbers[i] > *max)
        {
            *max = numbers[i];
        }
    }
}