#include <bits/stdc++.h>
using namespace std;
int n,k;//n la khach hang, k la luong khach max tren bus
int C[23][23];//chi phi giua cac thanh pho
int mincost = INT_MAX;
int cost[23];//chi phi tung buoc di
int pos[23];//vi tri cua tung buoc di
bool visited[23];//danh dau thanh pho da di
int passenger = 0;
int minDist;
bool check(int i, int j){
    if(passenger==k)//neu so khach tren xe full ma van chua di het n diem -> phai tra khach
        if(j<=n) return false;
    if(j > n)//neu da duyet qua n diem ma truoc do co diem chua tham -> phai di don khach
        if(!visited[j-n]) return false;
    if (C[pos[i-1]][j] == 0) return false;
    if (!visited[j]) return true;
    return false;
}

void solution(){
    if (C[pos[2*n]][0] == 0) return;
    int sum = cost[2*n] + C[pos[2*n]][0];
    mincost = min(sum,mincost);
}

void input(){
    cin >> n >> k;
    for (int i = 0; i <= 2*n;i++){
        for(int j = 0;j <= 2*n;j++ ){
            cin >> C[i][j];
        }
    }

}
void _try(int i){
    for(int j = 1;j <= 2*n;j++){
        if (check(i,j)){//check so hanh khach tren xe
            pos[i] = j;
            cost[i] = cost[i-1] + C[pos[i-1]][j];
            visited[j] = true;
            if(j <= n )  passenger++;
            else passenger--;

            if (i==2*n) solution();
            else 
                if(cost[i] + (2*n - i) * minDist < mincost) _try(i+1);

            visited[j] = false;
            if (j<=n) passenger--;
            else passenger++;

    }
    }
}
void findMin(){
    minDist = 2147483647;
    for(int i=0; i<=2*n; i++)
        for(int j=0; j<=2*n; j++){
            if(i!=j)
                minDist = min(minDist,C[i][j]);
        }
    return;
}
int main(){
    input();
    findMin();
    cost[0] = 0;
    pos[0] = 0;
    visited[0] = true;
    _try(1);
    cout<<mincost;
}