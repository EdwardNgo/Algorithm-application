#include <bits/stdc++.h>
using namespace std;
int m,n;//m la so outlet, n la so chi nhanh
int a[105];//so nhan vien cua moi chi nhanh
int cnt = 0;//dem so cach chia
int cost[105] = {0};
void input(){
    cin >> n >> m;
    for(int  i = 1;i<=n;i++){
        cin >> a[i];
    }
}
void solution(){
    if(cost[n] == m) cnt++;
}
void _try(int i){
    for(int j = 1;j<=m;j++){
        if(j % a[i] == 0){
            cost[i] = cost[i-1] + j;
            if(i == n) solution();
            else _try(i+1);
        }
    }
}

int main(){
    input();
    _try(1);
    // for(int i = 0;i<=n;i++){
    //     cout<<cost[i]<<" ";
    // }
    cout<<cnt;
}