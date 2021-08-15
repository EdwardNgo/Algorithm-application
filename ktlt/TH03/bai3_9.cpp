
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void generateAllStringsUtil(int K, char str[], int n, int k1, int k2)
{
    if (n == K)
    {
        // terminate binary string
        str[n] = '\0';
        cout << str;
        cout << endl;
        return;
    }
    if (k1 <= 0 || k2 < 0)
    {
        return;
    }
    if (n > K)
    {
        return;
    }

    if (str[n - 1] == '0')
    {
        for (int j = k1; j <= k2; j++)
        {
            for (int i = n; i < n + j; i++)
            {
                str[i] = '1';
            }
            generateAllStringsUtil(K, str, n + j, k1, k2);
        }
    }

    if (str[n - 1] == '1')
    {
        // cout << "hi";
        if (n != 1)
        {
            str[n] = '0';
            generateAllStringsUtil(K, str, n + 1, k1, k2);
        }
        else
        {

            for (int j = k1; j <= k2; j++)
            {
                for (int i = n; i < n + j; i++)
                {
                    str[i] = '1';
                }
                generateAllStringsUtil(K, str, n + j - 1, k1, k2);
            }
        }
    }
}

// function generate all binary string without
// consecutive 1's
void generateAllStrings(int K, int k1, int k2)
{
    // Base case
    if (K <= 0)
        return;

    // One by one stores every binary string of length K
    char str[K + 1];

    // Generate all Binary string starts with '0'
    str[0] = '0';
    generateAllStringsUtil(K, str, 1, k1, k2);

    // Generate all Binary string starts with '1'
    str[0] = '1';
    generateAllStringsUtil(K, str, 1, k1, k2);
}

// Driver program to test above function
int main()
{
    int K, k1, k2;
    cin >> K >> k1 >> k2;
    generateAllStrings(K, k1, k2);
    return 0;
}
