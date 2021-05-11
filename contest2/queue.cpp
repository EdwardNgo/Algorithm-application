#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int p[100000];
    // int count[100000] = {-1};
    int count[100000];
    cin >>n;
    for(int i =1 ;i<=n;i++){
        cin >> p[i];
        count[i] = -1;
    }
    for(int i = 1;i<=n;i++){
        for(int j = n;j>=i;j--){
            if (p[i] > p[j]){
                // cout<<j<<" "<<i<<" "<<j - i - 1<<endl;
                count[i] = j - i - 1;
                break;
            } 
        }
    }
    for(int j = 1;j<=n;j++){
        cout<<count[j]<<" ";
    }
}