#include <stdio.h>
#include <stdlib.h>
int main()
{
      printf("Ho Va Ten: Ngo Song Viet Hoang\n");
      printf("MSSV: 20183542\n\n");
      int *a, n, i, j, t;
      printf("Enter the number of elements: ");
      scanf("%d", &n);
      a = (int *)malloc(n * sizeof(int));
      printf("The input array is:\n");

      for (i = 0; i <= n - 1; i++)
      {
            scanf("%d", (a + i));
      }
      for (i = 0; i < n; i++)
            printf("%d ", *(a + i));
      for (i = 0; i < n; i++)
      {
            for (j = 0; j <= i; j++)
            {
                  if (*(a + i) < *(a + j))
                  {
                        t = *(a + i);
                        *(a + i) = *(a + j);
                        *(a + j) = t;
                  }
            }
      }
      printf("\nThe sorted array is: \n");
      for (i = 0; i < n; i++)
            printf("%d ", *(a + i));
      return 0;
}
