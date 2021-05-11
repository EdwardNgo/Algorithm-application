#include <bits/stdc++.h>
using namespace std;
int n,m;
int X[10000];
int Y[10000];
int L[10000][10000];

int main(){
        cin >> n >> m;  
        for(int i = 1;i<=n;i++){
            cin>> X[i];
            L[i][0] = 0;
        }
        for(int j = 1;j<=m;j++){
            cin>> Y[j];
            L[0][j] = 0;
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if (X[i] == Y[j]){
                    L[i][j] = L[i-1][j-1] + 1;
                }else{
                    L[i][j] = max(L[i-1][j],L[i][j-1]);
                }
            }
        }
        // for(int i = 1;i<=n;i++){
        //     for(int j = 1;j<=m;j++){
        //         cout<<L[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        cout<<L[n][m];
        

    }