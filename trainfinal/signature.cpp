#include <bits/stdc++.h>
using namespace std;
int N,M;
int C[105][505];
bool visited[105][505] = {false};
int route[105][505];
int res = INT_MIN;
void input(){
    cin >> M >> N;
    for (int i = 1;i<=M;i++){
        for (int j = 1;j<=N;j++){
            cin >> C[i][j];//chi phi cho nhan vien o tang i phong j
        }
    }
}
void _try(int i){// try so tang
    for(int j = 1;j<=N;j++){//so phong trong tang
        if(i == 1){
            visited[i][j] = true;
            route[i][j] += C[i][j];
            _try(i+1);
            visited[i][j] =false;
        }
        else if(visited[i-1][j]){
            visited[i][j] = true;
        }
    }
}
bool check(int i,int j){
    if (i == 1) return true;
    if (!visited[i][j]) return true;
}
void solution(){

}
int main(){
    cout<<visited[0][0];
}