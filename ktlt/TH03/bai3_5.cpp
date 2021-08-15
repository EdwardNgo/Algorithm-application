#include <iostream>
using namespace std;

int binom(int n, int k)
{
    if (k > n)
        return 0;
    if (k == 0)
        return 1;
    return binom(n - 1, k) + binom(n - 1, k - 1);
}
int GT(int n)
{
    int k = 0;
    int res = 1;
    while (k < n)
    {
        res = ++k * res;
    }
    return res;
}
int binom2(int n, int k)
{

    //# Khử đệ quy
    /*****************
    # YOUR CODE HERE #
    *****************/
    if (n < k)
    {
        return 0;
    }
    if(k==0){
        return 1;
    }
    else
    {
        return GT(n) / (GT(k) * GT(n - k));
    }
}

int main()
{
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n)
    {
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= m; ++n)
    {
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}