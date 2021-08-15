#include <stdio.h>
#include <stdlib.h>

// void allocate_mem(int ***mt, int m, int n)
// {
//     //#Allocate memory for the matrix

//     /*****************
//     # YOUR CODE HERE #
//     *****************/
//     mt = (int **)malloc(m * sizeof(int *));
//     for (int i = 0; i < m; i++)
//     {
//         mt[i] = (int *)malloc(n * sizeof(int));
//     }
// }

// void input(int **mt, int m, int n)
// {
//     //#Input elements of the matrix

//     /*****************
//     # YOUR CODE HERE #
//     *****************/
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             scanf("%d", &mt[i][j]);
// }

// void output(int **mt, int m, int n)
// {
//     //# Print all elements of the matrix

//     /*****************
//     # YOUR CODE HERE #
//     *****************/
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//             scanf("%d\t", &mt[i][j]);
//         printf("\n");
//     }
// }

// int process(int **mt, int m, int n)
// {
//     int tong = 0;
//     //# Calculate the sum of all even elements in the matrix

//     /*****************
//     # YOUR CODE HERE #
//     *****************/
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (mt[i][j] % 2 == 0)
//             {
//                 tong += mt[i][j];
//             }
//         }
//     }
//     return tong;
// }

// void free_mem(int **mt, int m, int n)
// {
//     //# Free memory

//     /*****************
//     # YOUR CODE HERE #
//     *****************/
// }

int main()
{
    int m, n, **mt;
    int sum = 0;
    printf("Ho Va Ten: Ngo Song Viet Hoang\n");
    printf("MSSV: 20183542\n\n");
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);
    // allocate_mem(&mt, m, n);
    // input(mt, m, n);
    // output(mt, m, n);
    // printf("The sum of all even elements is %d", process(mt, m, n));
    // free_mem(mt, m, n);
    // return 0;
    // dynamically create array of pointers of size M
    int **A = (int **)malloc(m * sizeof(int *)); // or int* A[M];
    if (A == NULL)
    {
        fprintf(stderr, "out of memory\n");
        exit(0);
    }

    // dynamically allocate memory of size M*N and let *A point to it
    *A = (int *)malloc(sizeof(int) * m * n);

    // position allocated memory across M pointers
    for (int r = 0; r < m; r++)
        A[r] = (*A + n * r);

    // assign values to allocated memory
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            printf("mt[%d][%d] = ",r,c);
            scanf("%d", &A[r][c]);
        }
    }
    // print the 2D array
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++){
            printf("%d ", A[r][c]);
        }
        printf("\n"); // or *(A[r] + c) or *(*(A + r) + c)
    }
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
            if (A[r][c] % 2 == 0)
            {
                sum += A[r][c];
            }
    }
    // deallocate memory
    printf("The sum of all even elements is %d", sum);
    free(*A);
    free(A);

    return 0;
}
