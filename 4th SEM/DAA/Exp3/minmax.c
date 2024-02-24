#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int max, min, max2, min2;

void maxmin(int a[], int i, int j)
{
    int max1, min1, mid;
    if (i == j)
    {
        max = min = a[i];
    }
    else
    {
        if (i == j - 1)
        {
            if (a[i] < a[j])
            {
                max = a[j];
                min = a[i];
            }
            else
            {
                max = a[i];
                min = a[j];
            }
        }
        else
        {
            mid = (i + j) / 2;
            maxmin(a, i, mid);
            max1 = max;
            min1 = min;
            maxmin(a, mid + 1, j);
            if (max < max1)
                max = max1;
            if (min > min1)
                min = min1;
        }
    }
}

int maxmin1(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return max, min;
}

int main()
{
    FILE *p = fopen("min-max.csv", "w");
    int i, num;
    for (int num = 1000; num <= 100000; num += 100)
    {
        int *a = (int *)malloc(num * sizeof(int));
        int *a1 = (int *)malloc(num * sizeof(int));
        for (int i = 0; i < num; i++)
        {
            a[i] = a1[i] = rand() % 100000 + 1;
        }

        clock_t start, end, start1, end1;

        max = a[0];
        min = a[0];
        max2 = a1[0];
        min2 = a1[0];

        start = clock();
        maxmin(a, 1, num);
        end = clock();
        double time = (double)(end - start) / CLOCKS_PER_SEC;

        start1 = clock();
        maxmin1(a1, num);
        end1 = clock();
        double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

        fprintf(p, "%d,%lf,%lf", num, time, time1);
        fprintf(p, "\n");
    }
    fclose(p);
    printf("done");
    return 0;
}