#include <stdio.h>
#define SIZE 5

main()
{ int i, j, k; int x[SIZE][SIZE]; for (i=0 ; i < SIZE ; i++)
    for (j=0 ; j < SIZE ; j++) x[i][j] = 0;
  i = (SIZE-1)/2; j = SIZE-1; for (k=1 ; k <= SIZE*SIZE ; k++) {
    if (x[i][j] != 0) { i = i-1; j = j-2; if (i < 0) i = i+SIZE;
      if (j < 0) j = j+SIZE; }
    x[i][j] = k; i++; if (i == SIZE) i = 0; j++; if (j == SIZE) j = 0;
  } for (i=0 ; i < SIZE ; i++) { for (j=0 ; j < SIZE ; j++)
      printf("%4d ", x[i][j]); printf("\n"); } }