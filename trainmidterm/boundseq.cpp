#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,M;
    int res = 0;
    int cnt = 0;
    cin >> n>>m>>M;
    int p[20000];
    for(int i = 1;i<=n;i++){
        cin >>p[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            res +=p[j];
            if(res <= M && res >= m) cnt++;
        }
        res = 0;
    }
    cout<<cnt;
}