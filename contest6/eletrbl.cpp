#include <bits/stdc++.h>
using namespace std;
int f,s,g,u,d;//so tang - xuat phat - dich - buoc len - buoc xuong
vector<vector<int>> a;//do thi luwu trang thai giua cac tang
int dist[1000004];// luu khoang cach de di chuyen den tang i
void input(){
    cin >> f >> s >> g >> u >> d;
    a.resize(f+1);
    for(int i  = 1;i<=f;i++){
        int up = i +u;
        int down = i - d;
        if(up <= f ) a[i].push_back(up);
        if(down > 0 ) a[i].push_back(down);
    }
    for(int i = 1;i<=f;i++){
        dist[i] = -1;
    }
}
void solution(){
    queue<int> q;
    q.push(s);//push dinh dau tien vao trong queue
    dist[s] = 0;
    //bfs tu dinh xuat phat la tang dau tien
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int v: a[x]){//bfs cac dinh
            if(dist[v] == -1){
                dist[v] = dist[x] + 1;
            }
            q.push(v);
            if(v == g) return;
        }
    }

}
int main(){
    input();
    solution();
    if (dist[g] == -1) cout<<"use the stairs";
    else cout<<dist[g];
}