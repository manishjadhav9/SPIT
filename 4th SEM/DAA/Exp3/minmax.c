#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 100000
// Function prototypes
void generateNumbers(int numbers[], int size);
void minMaxDivideConquer(int numbers[], int start, int end,
                         int *min, int *max);
void minMaxNaive(int numbers[], int size, int *min, int *max);
int main()
{
    FILE *p = fopen("minmax.csv", "w");
    fprintf(p, "Number, Time (Divide & Conquer), Time (Naive), Min, Max\n"); 

    // Hard-coded array with 10 values
    // int numbers[ARRAY_SIZE] = {54, 21, 87, 63, 91, 37, 20, 48, 66, 15};
    
    int numbers[ARRAY_SIZE]; 
    int min_dc, max_dc, min_naive, max_naive; 
    // Generate 100,000 random integer numbers using rand() 
    generateNumbers(numbers, ARRAY_SIZE); 
    printf("Number, Time (Divide & Conquer), Time (Naive), Min, Max\n"); 
    for (int i = 100; i <= ARRAY_SIZE; i += 100) 
    {
        clock_t start, end;

        // Divide and Conquer
        start = clock();
        minMaxDivideConquer(numbers, 0, i - 1, &min_dc, &max_dc);
        end = clock();
        double time_dc = ((double)(end - start)) /CLOCKS_PER_SEC;
        // Naive Approach
        start = clock();
        minMaxNaive(numbers, i, &min_naive, &max_naive);
        end = clock();
        double time_naive = ((double)(end - start)) /CLOCKS_PER_SEC;
        printf("%d, %lf, %lf, %d, %d\n", i, time_dc,time_naive, min_dc, max_dc);
        fprintf(p, "%d, %lf, %lf, %d, %d\n", i, time_dc,time_naive, min_dc, max_dc); 
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
    minMaxDivideConquer(numbers, start, mid, &min_left,&max_left);
    minMaxDivideConquer(numbers, mid + 1, end, &min_right,&max_right);
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

