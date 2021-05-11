#include <iostream>
using namespace std;
int isStart(int u,int *t){
    if (u == 1 || t[u] != t[u-1]){
        return 1; 
    } else {
        return 0;
    }
}
int main(){
    int n,q;
    cin >> n;
    int t[n];
    int res = 0;
    for (int i = 1; i <= n;i++) cin >> t[i];
    for (int i = 1; i <= n;i++) {
        res += isStart(i,t);
    }
    cin >> q;
    while (q--){
        int p,c;
        cin >> p >> c;
        res -= isStart(p,t);//khong biet mau moi co giong mau cu khong
        if (p < n) res -= isStart(p+1,t);
        t[p] = c;
        // for (int i = 1; i < n; i++){
        //     if (t[i] != t[i+1]) {
        //         // cout << t[i] <<" "<< t[i+1]<<" " << i;
        //         res +=1;
        //     }
        // }//O(q*n) 65 diem ve cho
        // // so phan duong bang so diem bat dau o phan duong khi t[i] thay doi thi chi thay doi o [i+1] va i
        res += isStart(p,t);
        if (p < n) res += isStart(p+1,t);
        cout <<res <<endl;
    }
}