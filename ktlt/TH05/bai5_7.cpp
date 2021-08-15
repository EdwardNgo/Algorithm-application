#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    for (int i = n; i != 0; i--)
    {
        int k, t;
        cin >> k >> t;
        while (k--)
        {
            int a;
            cin >> a;
            switch (t)
            {
            case 1:
                sum += a;
                break;

            case -1:
                sum -= a;
                break;
            }
            ans = max(ans, -sum);
        }
    }
    cout << ans;
}