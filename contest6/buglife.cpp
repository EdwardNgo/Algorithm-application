#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> A;
int color[2004];
void input(){
    cin >> n>> m;
    A.erase(A.begin(),A.end());
    A.resize(n+1);
    for(int i = 0;i<m;i++){
        int tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        A[tmp1].push_back(tmp2);
        A[tmp2].push_back(tmp1);
    }
}
void dfs(int u){
    for(int v: A[u]){
        if (color[v] == -1){
            color[v] = !color[u];
            dfs(v);
        }
    }
}
bool solution(){
    bool bipartie = true;
    for(int i = 0;i<=n;++i){
        color[i] = -1;
    }
    for(int i = 0;i<n;++i){
        if(color[i] == -1){
            color[i] = 0;
            dfs(i);
        }
    }
    for(int i = 0;i<n;++i){
        for( int v: A[i]){
            bipartie = bipartie & (color[i] != color[v]);
        }
    }
    return bipartie;
}
int main(){
    int T;
    cin >> T;
    int cnt = 1;
    while(T--){
        input();
        cout << "Scenario #" << cnt << ":" << endl;
        if(solution()) cout << "No suspicious bugs found!";
        else cout << "Suspicious bugs found!";
        cnt++;
        cout<<endl;
    }
}