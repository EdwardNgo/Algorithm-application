#include <bits/stdc++.h>
using namespace std;
int a[1000007];
int n;
int p[1000007]
int lais[1000007];
void input(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
}
void solution(){
    for(int i = 1;i<=n;i++){
        lais[i] = a[i];
        for(int j = 1;i<=n;i++){
            if(a[j]*lais[i] < 0 && abs(a[j]) > abs(a[i])){ 
                lais[]
            }
        }
    }
}