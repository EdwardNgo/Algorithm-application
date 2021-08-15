#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool found = false;
    for (int i = n; i != 0; i--)
    {
        int a;
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 100 == 0))
            found = true;
    }
    if (found)
        cout << "Yes";
    else
        cout << "No";
}