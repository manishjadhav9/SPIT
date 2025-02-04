#include <cstdio>
#include <cmath>

#define max 128  // Increased size to accommodate zero-padding

void Circular(float *x, int N, float *h, float *y);

int main()
{
    int i, L, M, N;
    float x[max], y[max];
    float h[max];

    // Initialize arrays to zero
    for(i = 0; i < max; i++)
    {
        x[i] = 0; h[i] = 0; y[i] = 0;
    }

    // Input length of x[n]
    printf("Enter the length of x[n] L = : ");
    scanf("%d", &L);

    // Input values of x[n]
    printf("Enter the values of x[n] : ");
    for(i = 0; i < L; i++)
    {
        scanf("%f", &x[i]);
    }

    // Input length of h[n]
    printf("Enter the length of h[n] M = : ");
    scanf("%d", &M);

    // Input values of h[n]
    printf("Enter the values of h[n] : ");
    for(i = 0; i < M; i++)
    {
        scanf("%f", &h[i]);
    }

    // Determine the length of the output sequence for linear convolution
    N = L + M - 1;

    // Zero-pad x[n] and h[n] to length N
    for(i = L; i < N; i++)
    {
        x[i] = 0;
    }
    for(i = M; i < N; i++)
    {
        h[i] = 0;
    }

    // Perform circular convolution (which will now behave as linear convolution)
    Circular(x, N, h, y);

    // Output the results
    printf("\n\n x[n] = ");
    for(i = 0; i < N; i++)
    {
        printf("  %4.2f  ", x[i]);
    }

    printf("\n\n h[n] = ");
    for(i = 0; i < N; i++)
    {
        printf("  %4.2f  ", h[i]);
    }

    printf("\n\n y[n] = ");
    for(i = 0; i < N; i++)
    {
        printf("  %4.2f  ", y[i]);
    }

    printf("\n\n");

    return 0;
}

/**************************************************************************/

void Circular(float *x, int N, float *h, float *y)
{
    int i, j, k, p, q, s, t;
    float sum = 0, temp[1024], signal[1024];

    // Reverse the signal h[n]
    j = 0;
    for(i = 0; i < N; i++)
    {
        j = N - 1 - i;
        temp[i] = h[j];
    }

    // Perform circular convolution
    for(s = 0; s < N; s++)
    {
        p = 0;
        for(t = 0; t < N; t++)
        {
            if(t <= s)
            {
                q = t - s + N - 1;
                signal[t] = temp[q];
            }
            else
            {
                signal[t] = temp[p];
                p++;
            }
        }
        sum = 0;
        for(i = 0; i < N; i++)
        {
            sum += x[i] * signal[i];
        }
        y[s] = sum;
    }
}