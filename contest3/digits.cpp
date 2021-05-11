#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
bool visited[11] = {false};
int x[11];

bool check(int i,int j){
    // if(j == 6 || j==2) return false;//d hieu sao van dc so 6 va 2
    if(!visited[j]) return true;
    return false; 
}
void solution(){
    x[10] = x[3];
    int ict = x[1]*100+x[2]*10 + x[3];
    int k62 = x[4]*100+x[5]*10+x[6];
    int hust = x[7]*1000+x[8]*100+x[9]*10+x[10];
    // cout<<ict<<" "<<" "<<k62<<" "<<hust<<" "<<ict-k62+hust<<endl;
    // for(int i = 1;i<=10;i++){
    //     cout<<x[i]<<" ";
    // }
    if(ict-k62+hust == n){
        cnt++;
    }  
     
}
void _try(int i){
    if(i == 5 || i==6){
       _try(i+1);
    }else{
        for(int j = 1;j<=9;j++){
            if(check(i,j)){
                visited[j] = true;
                x[i] = j;
                // cout<<i<<endl;
                if(i == 9) solution();
                else _try(i+1);
                visited[j] = false;
            }
        }   
    }
}
int main(){
    cin >>n;
    x[5] = 6;
    x[6] = 2;

    _try(1);
    // for(int i = 1;i<=10;i++){
    //     cout<<x[i]<<" ";
    // }
    cout<<cnt;
}