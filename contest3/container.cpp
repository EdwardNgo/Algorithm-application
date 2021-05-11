#include <bits/stdc++.h>
using namespace std;
int h,w;
int n;
int shape[13][2];
int main(){
    cin >> h >> w;
    cin>>n;
    int s = 0;
    for(int i = 1;i<=n;i++){
        int h1,w1;
        cin >> h1 >> w1;
        shape[i][1] = h1;
        shape[i][2] = w1;
        s+= h1*w1;
    }
    if(s>h*w){
        cout<<"0";
    }else{
        cout<<"1";
    }
}
