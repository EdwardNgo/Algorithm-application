#include <iostream>
using namespace std;
int lucas(int n)
{
    if (n == 0)
    {
        return 2;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return lucas(n - 1) + lucas(n-2);
    }
}