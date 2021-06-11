#include <bits/stdc++.h>
using namespace std;
int n;
int s[2000007];//thoi gian bat dau cua cuoc hop thu i
int t[2000007];//thoi gian ket thuc ...
int v[2000007];//khoang thoi gian cua cuoc hop thu i - gia tri
//output la gia tri lon nhat cua 2 cuoc hop khong trung nhau
//thuc ra la cuoc hop la cai may
int M = 2e6+7;
int ans = -1;
int maxV[2000007];//gia tri lon nhat tai thoi diem <= i
void input(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>s[i]>>t[i];
        v[i] = t[i] - s[i];
    }
}
void solution(){
    for(int i = 1;i<=n;i++){
        maxV[t[i]] = max(maxV[t[i]],v[i]);
    }
    for(int i = 1;i<M;i++){
        maxV[i] = max(maxV[i-1],maxV[i]);//tinh gia tri lon nhat tai thoi diem i
    }
    for(int i = 1;i<=n;i++){
        if(maxV[s[i] -1]>0){
            ans = max(ans,maxV[s[i] - 1] + v[i]);//s[i] - 1 la cai thoi gian ket thuc truoc do
        }
    }
}
int main(){
    input();
    solution();
    cout<<ans;
}