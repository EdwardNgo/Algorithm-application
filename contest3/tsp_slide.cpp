#include <bits/stdc++.h>
using namespace std;
int n,m;
bool bVisited[21];
int C[21][21];
int cmin = 2147483647;
int iRes[21];//truy vet duong di
int cost[21];//luu chi phi tung buoc di
bool check(int a, int i){
    if(C[iRes[a-1]][i] == 0) return false;
    if(!bVisited[i]) return true;
    return false;
}
void solution(){
    if(C[iRes[n]][1] == 0) return;
    int sum = cost[n] + C[iRes[n]][1];
    cmin = min(sum,cmin);
}
int _try(int k){//try het cac vi tri
    for(int i = 2;i<=n;i++){
        if(check(k,i)){
            iRes[k] = i;
            cost[k] = cost[k-1] + C[iRes[k-1]][i];
            bVisited[i] = true;
            if (k == n) solution();
            else 
                if (cost[k] < cmin) _try(k+1);//cat nhanh
            bVisited[i] = false;
        }
    }
}
int main(){
    cin >> n >> m;

    for (int k =1;k<=m;k++){
        int i,j,temp;
        cin >> i >> j >> temp;
        C[i][j] = temp;
    }
    iRes[1] = 1;
    cost[1] = 0;
    bVisited[1] = true;
    _try(2);
    cout<<cmin;
}