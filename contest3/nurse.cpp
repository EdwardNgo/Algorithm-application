#include <bits/stdc++.h>
using namespace std;
int n,k1,k2;
int cnt = 0;
int day[1000];
int workingday[1000];
const int du = 1000000000 + 7;

void input(){
    cin >>n >>k1>>k2;
}
bool check(int i , int j){
    if(i == 1) return true;
    else{
        if(j == 0){
            if(day[i-1] == 0) return false;//neu ngay truoc vua nghi thi phai di lam
            else{
                if(workingday[i-1] < k1) return false;//neu so ngay di lam truoc do van nho hon k1 thi khong duoc nghi
            }
        } else {
            if(day[i-1] == 0) {
                if(n-i+1<k1) return false;// neu ngay truoc nghi nhung nhung ngay tiep theo phien lam viec van it hon k1 thi bo truong hop nay
            }
            else {
                if(workingday[i-1] >= k2) return false;//neu ma so ngay di lam truoc do den gioi han thi khong phai di lam
            }
        }
        return true;
    }
}

void _try(int i){
    for(int j = 0;j<=1;j++){
        if(check(i,j)){
            day[i] = j; 
            if(j  == 1){
                workingday[i] = workingday[i-1] + 1;
            } else{
                workingday[i] = 0;
            }
            if (i == n) cnt++;
            else _try(i+1);
        }
    }
}
int main(){
    input();
    workingday[0] = 0;
    _try(1);
    cout<<cnt%du;
}
