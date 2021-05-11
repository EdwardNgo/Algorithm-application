#include <bits/stdc++.h>
using namespace std;
int n;
int d[16];
int mind[100] = {0};
int visited[16] = {false};
int minRes = INT_MAX;
int pos[16];
int t = 0;
int sum = 0;
void input(){
    cin >>n;
    for(int i = 1;i<=n;i++){
        cin >> d[i];
    }
    // sort(d,d+n);
}
void solution(){
    // int cnt = 0;
    // for(int k = 0;k<=100;k++){
    //     // cout<<mind[k]<<" ";
    //     if(mind[k] != 0){
    //         cnt++;
    //     }
    // }
    // cout<<endl;
    for(int k = 1;k<=100;k++){
        mind[k] = 0;
    }
    // cout<<cnt<<endl;
    // cout<<t<<endl;
    minRes = min(minRes,t);
    t = 1;
}
void solution2(){
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        if(d[i] + mind[cnt] <=6){
            mind[cnt] += d[i];
        }else if(d[i] +mind[cnt]>6){
            cnt++;
            mind[cnt] = d[i];
        }
    }
}
void solution3(){
    for(int i = 1;i<=n;i++){
        sum+=d[i];
    }
}
bool check(int i,int j){
    if(!visited[j]) return true;
    return false;
}
void _try(int i ){
    for(int j = 1;j<=n;j++){
        if(check(i,j)){
            visited[j] = true;
            pos[i] = d[j];
            // if(i == 1) {mind[i] = d[j];}
            if(d[j] + mind[t-1]<=6){
                mind[t-1] += d[j];
            }else if(d[j] + mind[t-1]>6){
                t =t+1;
                mind[t] = d[j];
            }
            if(i == n) solution();
            else _try(i+1);
            visited[j] = false;
        }
    }
}

int main(){
    input();
    t = 1;
    // _try(1);
    // mind[0] = 0;
    // // for(int k = 1;k<=5;k++){
    // //     cout<<pos[k];
    // // }
    // cout<<minRes;
    solution3();
    if(sum%6 == 0){
        cout<<sum/6;
    }else if(sum % 6 !=0){
        cout<<sum/6+1;
    }
    // solution2();
    // int cnt1 = 0;
    // for(int k = 0 ;k<=5;k++){
    //     // cout<<mind[k];
    //     if(mind[k] != 0){
    //         cnt1++;
    //     }
    // }
    // cout<<cnt1;
}
