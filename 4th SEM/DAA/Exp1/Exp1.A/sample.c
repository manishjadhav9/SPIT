#include <stdio.h>
#include <math.h>

// Function prototypes
double linear(int n);                    // Returns n
double powerOfTwo(int n);                // Returns 2^n
double cubic(int n);                     // Returns n^3
double nLogN(int n);                     // Returns n * log2(n)
double logFactorial(int n);              // Returns (lg n)! (Factorial of logarithm)
double lnLnN(int n);                     // Returns ln(ln(n))
double nTimesTwoToN(int n);              // Returns n * 2^n
double powerOfTwoLog(int n);             // Returns 2^lg(n)
double lnN(int n);                       // Returns ln(n)
double exponentialTwoTwoNPlusOne(int n); // Returns 2^(2^n+1)
double factorial(int n);                 // Returns n!

// Function implementation of n
double linear(int n)
{
  return n;
}

// Function implementation of 2^n
double powerOfTwo(int n)
{
  return pow(2, n);
}

// Function implementation of n^3
double cubic(int n)
{
  return pow(n, 3);
}

// Function implementation of n * log2(n)
double nLogN(int n)
{
  return n * log2(n);
}

// Function implementation of (lg n)! (Factorial of logarithm)
double logFactorial(int n)
{
  return tgamma(log2(n) + 1); // Using tgamma for gamma function (factorial )
}

// Function implementation of ln(ln(n))
double lnLnN(int n)
{
  return log(log(n));
}

// Function implementation of n * 2^n
double nTimesTwoToN(int n)
{
  return n * pow(2, n);
}

// Function implementation of 2^lg(n)
double powerOfTwoLog(int n)
{
  return pow(2, log2(n));
}

// Function implementation of ln(n)
double lnN(int n)
{
  return log(n);
}

// Function implementation of 2^(2^n+1)
double exponentialTwoTwoNPlusOne(int n)
{
  return pow(2, pow(2, n) + 1);
}

// Function implementation of n!
double factorial(int n)
{
  if (n == 0 || n == 1)
    return 1;
  else
    return n * factorial(n - 1);
}

int main()
{
  int n;

  // Calculate and display values for n from 0 to 100 with an increment of 1
  for (n = 0; n <= 100; n++)
  {
    printf("n = %d:\n", n);
    printf("1. n: %d\n", (int)linear(n));
    printf("2. 2^n: %f\n", powerOfTwo(n));
    printf("3. n^3: %f\n", cubic(n));
    printf("4. n lg n: %f\n", nLogN(n));
    printf("5. (lg n)! (Factorial of logarithm): %f\n", logFactorial(n));
    printf("6. ln ln n: %f\n", lnLnN(n));
    printf("7. n*2^n: %f\n", nTimesTwoToN(n));
    printf("8. 2^lg n: %f\n", powerOfTwoLog(n));
    printf("9. ln n: %f\n", lnN(n));
    printf("10. 2^(2^n+1): %f\n", exponentialTwoTwoNPlusOne(n));
    printf("\n");
  }

  // Calculate and display values for n from 0 to 20 with an increment of 1 for the factorial function
  printf("Factorial Function (n!):\n");
  for (n = 0; n <= 20; n++)
  {
    printf("n = %d: %.0f\n", n, factorial(n));
  }

  return 0;
}