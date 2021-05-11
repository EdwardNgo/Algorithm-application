//k xe giong nhau moi xe co Q
//n khach hang yeu cau d[i] goi hang
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int d[10];
int c[5];//so khach duoc cac xe phuc vu
int q[20];//mang luu khoi luong cac xe phuc vu khach hang
int dist[30][30];
int mindist = INT_MAX;
int sum = 0;
int cost[5][12];//chi phi cua tung xe tai
bool visited[12];//mang luu vi tri da tham
int pos[5][12];//mang luu vi tri hien tai tung xe tai
int n,K,Q;


void solution(){
    mindist = min(mindist,sum);
}
void _try(int i){//try het khach hang

    for(int k=1;k<=K;k++){//try het xe
        // for(int j = 1;j<=n;j++){
        if(q[k] >= d[i]){
            q[k] -= d[i];//init q[k] = Q;
            pos[k][i] = i;
            cost[k][i] = cost[k][i-1] + dist[pos[k][i-1]][i];
            if (i == n){
                solution();
            }
            _try(i+1);
            q[k] += d[i];
        } 
        sum += cost[k][i-1] + dist[pos[k][i-1]][0];


    }
}
int main(){
    cin>>n>>K>>Q;
    for(int i = 1;i<=n;i++){
        cin >> d[i];
    }
    for(int k=1;k <= K;k++){
        c[k] = 0;
        q[k] = Q;
    }
    for (int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            int temp;
            cin >>temp;
            dist[i][j] = temp;
        }
    }
    for (int k = 1;k<=K;k++){
        pos[k][0] = 0;
        cost[k][0] = 0;
    }
    _try(1);
    // cout<<mindist;
}


