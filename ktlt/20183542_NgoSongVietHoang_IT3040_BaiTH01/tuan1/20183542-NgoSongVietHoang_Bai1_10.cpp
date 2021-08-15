#include <stdio.h>
int main()
{
    int r, c, a[100][100], b[100][100], sum[100][100], mul[100][100], i, j;
    printf("Ho Va Ten: Ngo Song Viet Hoang\n");
    printf("MSSV: 20183542\n\n");
    scanf("%d", &r);

    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < r; ++j)
        {
            scanf("%d", &a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < r; ++j)
        {
            scanf("%d", &b[i][j]);
        }
        printf("\n");
    }

    // adding two matrices
    for (i = 0; i < r; ++i)
        for (j = 0; j < r; ++j)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    for (i = 0; i < r; ++i)
        for (j = 0; j < r; ++j)
        {
            printf("%d   ", sum[i][j]);
            if (j == r - 1)
            {
                printf("\n\n");
            }
        }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < r; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    //for printing result
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("%d\t", mul[i][j]);
        }
        printf("\n");
    }

    // printing the result

    return 0;
}
