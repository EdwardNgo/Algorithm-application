#include <bits/stdc++.h>
using namespace std;
int n,k,i;//do dai,vi tri,so so 0 lien tiep
int binary[100000];//luu gia tri xau cuoi cung
int pos[100000];//luu gia tri so 0 lien tiep
int cnt = 0;
void input(){
    cin>>n>>k>>i;
}
void printSolution(){
    for(int i = 1;i<=n;i++){
        // if(i != n){
        // cout<<binary[i]<<" ";
        // } else{
        //     cout<<binary[i];
        // }
        cout<<binary[i]<<" ";
    }
}
bool check(int a,int j){
    if (cnt >= k) return false;//tai sao phai cat luon nhi
    if (a == 1) return true;
    else {
        if(j == 0){
            if(pos[a-1] + 1 == i) return false;//neu truoc do so so 0 da den gioi han thi khong duoc dien tiep
        }else{
        return true;
        }
    }
}
void solution(){
    cnt++;
    if(cnt == k) printSolution();
}
void _try(int a){
    for(int j =0;j<=1;j++){
        if(check(a,j)){
            binary[a] = j;
            if(j == 0){
                pos[a] = pos[a-1] + 1;
            } else{
                pos[a] = 0;
            }
            if(a == n) solution();
            else _try(a+1);
        }
    }
}
int main(){
    input();
    pos[0] = 0;
    _try(1);
    // cout<<cnt;
    if(cnt < k){
        cout<<"-1";
    }

}
