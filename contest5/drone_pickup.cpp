#include <bits/stdc++.h>
using namespace std;
int N,K;//N la so chang, K la so chang toi da ma drone co the qua
int a[1005];// a la nang luong drone nhan duoc o chang thu i
int c[1005];// c la khoi luong drone nhan duoc o chang thu i
int dp[1005][105];// dp[i][k] la khoi luong hang lay duoc tai diem i va so luong diem da lay khong vuot qua k
int ans = INT_MIN;
void input(){   
    cin>>N>>K;
    for(int i = 1;i<=N;i++){
        cin >> a[i];
    }
    for(int i = 1;i<=N;i++){
        cin>>c[i];
    }
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=K+1;j++){
            dp[i][j] = 0;
        }
    }
}
void solution(){
    for(int i = N;i>=1;i--){
        for(int k = 1;k<=K+1;k++){
            for(int j = i + 1;j<=i+a[i];j++){//Nhung vi tri tiep theo ma drone co the bay toi
                dp[i][k] = max(dp[i][k],dp[j][k-1] + c[i]);
            }
            ans = max(ans,dp[1][k]);
        }
    }
}
int main(){
    input();
    solution();
    // for(int i = 1;i<=N;i++){
    //     for(int k = 1;k<=K+1;k++){
    //         cout<<dp[i][k]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<ans;
}