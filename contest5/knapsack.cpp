#include <bits/stdc++.h>
using namespace std;
int n,b;
int w[31];
int c[31];
int maxValue(int n,int b,int w[],int c[]){
    long long result[n+1][b+1];
    for(int i = 0;i<=n;i++) result[i][0] = 0;
    for(int i = 0;i<=b;i++) result[0][i] = 0;
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=b;j++){
            if(j > w[i]) result[i][j] = max(result[i-1][j],result[i-1][j-w[i]] + c[i]);
            else result[i][j] = result[i-1][j];
        }
    }
    return result[n][b];
}
void input(){
    int n,b;
    cin >> n >> b;
    for(int i = 1;i<=n;i++){
        cin >> w[i] >> c[i];
    }
}