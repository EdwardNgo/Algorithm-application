#include <bits/stdc++.h>
using namespace std;
int n,m,testcase;
int a[105];
int b[105];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int cnt = 0;
    cin >> testcase;
    while(testcase--){
        cin >> n;
        for(int i = 1;i<=n;i++){
            cin >> a[i];
        }
        cin >> m;
        for(int i = 1;i<=m;i++){
            cin >> b[i];
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(b[j] == a[i]){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}