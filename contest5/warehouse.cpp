#include <bits/stdc++.h>
using namespace std;
int n,t,d;
int a[1005];
int ptime[1005];
int dp[1005][105];

void input(){
    cin >> n >> t >> d;//t la max time
    for (int i = 1; i<=n;i++){
        cin >> a[i];

    }
    for (int i = 1; i<=n;i++){
        cin >> ptime[i];

    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<=t;j++){
            dp[i][j]=0;
            // if(i==0&&j>=ptime[1]) dp[i][j]=a[0];
            //cout<< f[i][j];
        }
        //cout<< endl;
    }

}
int main(){
    int ans = 0;
    input();
    for (int i = 1;i<=n;i++){//xet qua n chang
        for(int k = ptime[i];k<=t;k++){ //xet thoi gian toi da
            for(int j = i - 1;j>=max(0,i-d);j--){//yeu cau khoang cach phai nho hon hoac bang d
                // cout<<dp[i][k]<<" ";
                dp[i][k] = max(dp[i][k],dp[j][k-ptime[i]] + a[i]);
            }
            ans = max(ans,dp[i][k]);
        }
    }

    cout<<ans;
}