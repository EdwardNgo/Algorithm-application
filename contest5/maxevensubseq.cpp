#include <bits/stdc++.h>
using namespace std;
int a[1000007];
int n;
int dp[1000007];
void input(){
    cin >> n;
    for(int i = 1;i<=n ;i++){
        cin >> a[i];
    }
}
void solution(){
    dp[1] = a[1];
    int max_current = a[1];
    for(int i =2; i<=n;i++){
        max_current = max(max_current + a[i],a[i]);
        dp[i] = max(dp[i-1],max_current);
    }
}
int main(){
    input();
    solution();
    int ans = INT_MIN;
    for(int i = 1;i<=n;i++){
        if(dp[i] > ans && dp[i] % 2 == 0) ans = dp[i];
        cout<<dp[i]<<" ";
    }
    if (ans == INT_MIN) { cout<<"NOT_FOUND";}
    else{cout<<ans;}
}