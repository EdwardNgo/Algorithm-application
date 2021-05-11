#include <bits/stdc++.h>
using namespace std;
int n,m;
int relation[100][100]={0};
int dress[100];//gia cua moi chiec vay
int res = INT_MAX;
int cost[100];//gia cua i chiec vay khi chon xong
int temp[100];//luu cac vay da mua
int bought[100] = {false};// vay da mua 
void input(){
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        // int temp;
        // cin>> temp;
        cin >> dress[i];
    }
    for(int j = 1;j<=m;j++){
        int temp1,temp2;
        cin >>temp1>>temp2;
        relation[temp1][temp2] = relation[temp2][temp1] = 1;
    }
    
}
bool check(int i,int j){
    if(relation[temp[i-1]][j] != 1 && temp[i-1] != 0) return false;//neu ma cai tiep theo khong co lien ket
    if(!bought[j]) return true;
    return false;
}
void solution(){
    if(relation[temp[3]][temp[1]] == 0) return;//cai cuoi khong co lien ke voi cai dau
    res = min(res,cost[3]);
}
void _try(int i){//max try 3 vay
    if (m < 3) {
        res = -1;
        return;
    }
    
    for(int j = 1;j<=n;j++){//try het cac vay
        if(check(i,j)){
            bought[j] = true;//danh dau la vay da mua
            temp[i] = j;
            cost[i] = cost[i-1] + dress[j];
            if (i == 3) solution();
            else _try(i+1);
            bought[j] = false;
        }
    }
}

int main(){
    input();
    cost[0] = 0;
    temp[0] = 0;
    _try(1);
    // for(int i = 1;i<=n;i++){
    //     cout<<cost[i]<<"-";
    //     cout<<temp[i]<<" ";
    // }
    if (res == INT_MAX){
        cout<<-1;
    } else{
        cout<<res;
    }
}