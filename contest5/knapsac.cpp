#include <bits/stdc++.h>
using namespace std;
long long n,b;
long long dp[31][1000007];//gia tri toi da cua cai tui khi mang i do vat va max j khoi luong
long long a[31];//trong luong cua do vat
long long c[31];//gia tri cua do vat

void input(){
    cin >> n >>b;
    for(int i = 1; i<=n;i++){
        cin >> a[i] >> c[i];
    }
}
void solution(){
    for(int i = 0;i<=n;i++) dp[i][0] = 0;
    for(int i = 0;i<=b;i++) dp[0][i] = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=b;j++){
            if(j >= a[i]) dp[i][j] = max(dp[i - 1][j],dp[i - 1][j-a[i]] + c[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
}
int main(){
    input();
    solution();
    cout<< dp[n][b];
}