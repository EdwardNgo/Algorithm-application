// cho mot do thi day du co trong so
// tim cach di chuyen qua moi dinh dung mot lan va tong trong so nho nhat

//duyet toan bo -> de quy quay lui -> de qui nhanh can
// de qui nhanh can du
// goi minC = min(c[][])
// can duoi sum + c[x[i-1][j]] +minC*(n-i) // minC*(n-i) tuc la n -i canh con lai co gia tri lac quan nhat la minC
#include <bits/stdc++.h>
using namespace std;
int n,m;
int c[20][400];
int x[20];
int mark[400];
int best = 99999;
int minC = 9999;
void duyet(int i,int sum){
    if(i==n+1){
        if(sum + c[x[n]][i] < best){
            best = sum + c[x[n]][i];
        }
        return;
    }
    for(int j = 2;j<=n;++j){
        if (!mark[j]){
            if (sum + c[x[n]][j] + minC*(n-i)<best){
                mark[j] = i;
                x[i] = j;
                duyet(i+1,sum + c[x[i-1]][j]);
                mark[j] = 0;
            }
        }
    }
}

int main(){
    cin >> n >>m;
    for(int i = 1;i<=n;i++){
        x[i] = i;
    }
    for (int i = 1;i<=n;i++){
        for(int j = 1;j<=n;i++){
            c[i][j] = 0;
        }
    }
    while(m--){
        int j,i,k;
        cin>>i>>j>>k;
        c[i][j] = k;
    }
    for (int i = 1;i<=n;i++){
        for(int j = 1;j<=n;i++){
            if (c[i][j]<minC && c[i][j] != 0){
                minC = c[i][j];
            }
        }
    }
    duyet(2,0);
    cout<<best;
}