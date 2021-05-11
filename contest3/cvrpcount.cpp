//k xe giong nhau moi xe co Q
//n khach hang yeu cau d[i] goi hang
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int d[10];
int c[5];//so khach duoc cac xe phuc vu
int q[20];//mang luu khoi luong cac xe phuc vu khach hang
int n,K,Q;

int res;
int custom_fact(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    return custom_fact(n-1)*n;
}
void _try(int i){
    if (i == n){
        int tmp = 1;
        for(int k=1;k<=K;k++){
            tmp*=custom_fact(c[k]);//thu tu phuc vu khac nhau -> phai giai thua
        }
        res += tmp;
        return;
    }
    for(int k=1;k<=K;k++){
        if(q[k] >= d[i]){
            q[k] -= d[i];//init q[k] = Q;
            c[k]++;//init c[k] =0 tinh so khach duoc xe k phuc vu
            _try(i+1);
            q[k] += d[i];
            c[k] --;

        }
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
    _try(0);
    cout<<res/custom_fact(K)<<endl;//thay doi xe de phuc vu khach khong anh huong 
}


