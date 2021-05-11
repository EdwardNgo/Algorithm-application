#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
bool visited[11] = {false};
int x[11];

bool check(int i,int j){
    // if(j == 6 || j==2) return false;//d hieu sao van dc so 6 va 2
    if(i == 2 && j==0) return false;
    if(!visited[j]) return true;
    return false; 
}
void solution(){
    x[6] = x[2];
    x[7] = x[2];
    x[8] = x[2];
    x[10] = x[3];
    int ctdlgt = x[1]*100000+x[2]*10000+x[3]*1000+x[4]*100+x[5]*10+x[6];
    int ttud = x[7]*1000+x[8]*100+x[9]*10+x[10];
    if(ctdlgt+ttud == n){
        cnt++;
    }
     
}
void _try(int i){
    if(i==6 || i == 7 || i== 8){
       _try(i+1);
    }else{
        for(int j = 0;j<=9;j++){
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
    cin>>n;
    _try(1);
    cout<<cnt;
}