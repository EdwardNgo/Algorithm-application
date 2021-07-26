#include <bits/stdc++.h>
using namespace std;
int N,K;//N la so chang, K la so chang toi da ma drone co the qua
int a[3005];// a la nang luong drone nhan duoc o chang thu i
int c[3005];// c la khoi luong drone nhan duoc o chang thu i
int dp[3005][105];// dp[i][k] la khoi luong hang lay duoc tai diem i va so luong diem da lay khong vuot qua k
//bai nay drone phai den diem cuoi cung 
int d = 0;//cai nay la khoang cach giong trong bai warehouse - tim cai khoang cach lon nhat drone bay duoc
int ans = -1;
void input(){   
    cin>>N>>K;
    for(int i = 1;i<=N;i++){
        cin>>c[i];
    }
    for(int i = 1;i<=N;i++){
        cin >> a[i];
        d = max(d,a[i]);
    }

    for(int i = 1;i<=N;i++){
        for(int j = 0;j<=K+1;j++){
            dp[i][j] = INT_MIN;
        }
    }
}
// void solution(){
//     for(int i = N;i>=1;i--){
//         for(int k = 1;k<=K+1;k++){
//             for(int j = i + 1;j<=i+a[i];j++){//Nhung vi tri ma tu do co the den dinh i
//                 dp[i][k] = max(dp[i][k],dp[j][k-1] + c[i]);
//             }
//             ans = max(ans,dp[1][k]);
//         }
//     }
// }
void solution_2(){
    dp[1][1] = c[1];
    for(int i = 1;i<=N;i++){
        for (int k = 1;k<=K+1;k++){
            for(int j = i-1;j >= max(1,i-d);j--){// ta gia su khoang cach co dinh giong bai warehouse
                if(j + a[j] >= i){//check them dieu kien nua la tu do co den duoc diem dang xet khong
                    dp[i][k] = max(dp[i][k],dp[j][k-1] + c[i]);
                }
            }
        }
    }
    for(int k = 1;k<=K+1;k++){
        ans = max(ans,dp[N][k]);
    }
    // for(int i = 1;i<=N;i++){
    //     for(int j = 1;j<=K+1;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
int main(){
    input();
    solution_2();
    cout<<ans;
}