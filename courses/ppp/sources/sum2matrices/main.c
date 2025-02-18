#include <stdio.h>

#define ar 2
#define ac 2
#define br 2
#define bc 2
#define cr 2
#define cc 2

void add2matrices(float a[ar][ac], float b[br][bc], float result[cr][cc]);

int main()
{
  float a[ar][ac], b[br][bc], result[cr][cc];

  printf("Enter elements of 1st matrix\n");
  for (int i = 0; i < ar; ++i)
    for (int j = 0; j < ac; ++j)
    {
      printf("Enter a%d%d:", i , j);
      scanf("%f", &a[i][j]);
    }

  printf("\nEnter elements of 2nd matrix\n");
  for (int i = 0; i < br; ++i)
    for (int j = 0; j < bc; ++j)
    {
      printf("Enter b%d%d:", i, j);
      scanf("%f", &b[i][j]);
    }

  add2matrices(a, b, result);

  // Displaying a[ar][ac] + b[br][bc]
  printf("\n+++++\n");
  printf("\nSum Of Matrix\n");

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
    {
      printf("%.2f ", result[i][j]);

      if (j == 1)
        printf("\n");
    }
  return 0;
}

void add2matrices(float a[ar][ac], float b[br][bc], float result[cr][cc]){

    // Adding a[ar][ac] + b[br][bc]
    for (int i = 0; i < cr; ++i)
        for (int j = 0; j < cc; ++j)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
}

