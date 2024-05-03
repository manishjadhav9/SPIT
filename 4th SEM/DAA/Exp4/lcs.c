#include <stdio.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b)
{
  return (a > b) ? a : b;
}

// Function to find the length of longest common subsequence
// and print one of the common subsequences along with its length
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

  int index = L[m][n];
  char lcs[index + 1];
  lcs[index] = '\0';

  i = m;
  j = n;
  while (i > 0 && j > 0)
  {
    if (X[i - 1] == Y[j - 1])
    {
      lcs[index - 1] = X[i - 1]; 
      i--;
      j--;
      index--; 
    }
    else if (L[i - 1][j] > L[i][j - 1])
      i--;
    else
      j--;
  }

  printf("Longest Common Subsequence: %s\n", lcs);
  printf("Length of Longest Common Subsequence: %d\n", L[m][n]);
  printf("Trace Path:\n");
  for (int a = 0; a <= m; a++)
  {
    for (int b = 0; b <= n; b++)
    {
      printf("%d ", L[a][b]);
    }
    printf("\n");
  }
}



int main()
{
  char X[50], Y[50];
  printf("Enter first sequence: ");
  scanf("%s", X);
  printf("Enter second sequence: ");
  scanf("%s", Y);
  int m = strlen(X);
  int n = strlen(Y);
  lcs(X, Y, m, n);
  return 0;



  //  char X[] = "AGGTAB";
  // char Y[] = "GXTXAYB";
  // int m = strlen(X);
  // int n = strlen(Y);
  // lcs(X, Y, m, n);
  // return 0;
}