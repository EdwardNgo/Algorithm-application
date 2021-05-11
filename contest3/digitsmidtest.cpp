#include <bits/stdc++.h>
using namespace std;
bool visited[11] = {false};
int x[11];
int n;
int cnt;
bool check(int i,int j){
    // if(j == 6 || j==2) return false;//d hieu sao van dc so 6 va 2
    // if(i == 5) return false;
    if(i == 1&& j == 0) return false;
    if(i == 3&& j == 0) return false;
    if(!visited[j]) return true;
    return false; 
}
void solution(){
    // x[10] = x[3];
    // int ict = x[1]*100+x[2]*10 + x[3];
    // int k62 = x[4]*100+x[5]*10+x[6];
    // int hust = x[7]*1000+x[8]*100+x[9]*10+x[10];
    // // cout<<ict<<" "<<" "<<k62<<" "<<hust<<" "<<ict-k62+hust<<endl;
    // // for(int i = 1;i<=10;i++){
    // //     cout<<x[i]<<" ";
    // // }
    // if(ict-k62+hust == n){
    //     cnt++;
    // }
    x[5] = x[3];  
    x[9] = x[4];
    int hust = x[1]*1000+x[2]*100+x[3]*10+x[4];
    int soict = x[5]*10000+x[6]*1000+x[7]*100+x[8]*10+x[9]; 
    if(hust+soict == n){
        cnt++;
    }
}
void _try(int i){
    if(i == 5){
        _try(i+1);
    }else{
    for(int j = 0;j<=9;j++){
        if(check(i,j)){
            visited[j] = true;
            x[i] = j;
            // cout<<i<<endl;
            if(i == 8) solution();
            else _try(i+1);
            visited[j] = false;
        }
    }  
    } 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin >>n;
        cnt = 0;
        _try(1);
        // for(int i = 1;i<=10;i++){
        //     cout<<x[i]<<" ";
        // }
        cout<<cnt;
    }
}