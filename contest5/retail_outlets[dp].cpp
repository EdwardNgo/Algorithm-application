#include <bits/stdc++.h>
using namespace std;
int m,n;//m la so outlet, n la so chi nhanh
//f[i][j] la cach phan bo j cua hang cho i chi nhanh dau tien
//ket qua f[n][m]
int f[105][505];
int a[105];//so nhan vien cua moi chi nhanh
void input(){
    cin >> n >> m;
    for(int  i = 1;i<=n;i++){
        cin >> a[i];
    }
}


int main(){
    input();
    f[0][0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = a[i];j<=m;j++){//so cach phan bo cho a[i] -> m outlet cho i chi nhanh
            for(int k = a[i];k<=j;k+=a[i]){
                f[i][j] = (f[i][j] + f[i-1][j-k])%1000000007;
            }
        }
    }  
    cout<<f[n][m];
}