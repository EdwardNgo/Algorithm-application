#include <bits/stdc++.h>
using namespace std;
int n,k;//do dai,vi tri
int permutation[100000];//luu gia tri xau cuoi cung
int pos[100000];//luu gia tri so 0 lien tiep
bool visited[100000] = {false};
int cnt = 0;
void input(){
    cin>>n>>k;
}
void printSolution(){
    for(int i = 1;i<=n;i++){
        cout<<permutation[i]<<" ";
    }
}
bool check(int a,int j){
    if (cnt >= k) return false;
    if (!visited[j]) return true;
    return false;
}
void solution(){
    cnt++;
    // cout<<cnt<<endl;
    if(cnt == k) printSolution();
}
void _try(int a){
    for(int j =1;j<=n;j++){
        if(check(a,j)){
            visited[j] = true;
            permutation[a] = j;
            if(a == n) solution();
            else _try(a+1);
            visited[j] = false;
        }
    }
}
int main(){
    input();
    pos[0] = 0;
    _try(1);
    if(cnt < k){
        cout<<"-1";
    }

}
