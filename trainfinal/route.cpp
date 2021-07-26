#include <bits/stdc++.h>
using namespace std;
int n,m;//so dinh va canh cua do thi
int c[20005][20005];
int route[100005];
int k;
int ans = 0;
void input(){
    cin>>n>>m;
    for(int i =0;i<m;i++){
        int dst,src,value;
        cin >> dst>>src>>value;
        c[dst][src] = value;
        c[src][dst] = value;
    }
    cin >> k;
    for (int i = 1;i<=k;i++){
        cin >> route[i];
    }
}
void solution(){
    for(int i = 2;i<=k;i++){
        if(c[route[i-1]][route[i]] == 0){
            ans = -1;
            return;
        }else{
            ans += c[route[i-1]][route[i]];
        }
    }
}
int main(){
    input();
    solution();
    cout<<ans;
}