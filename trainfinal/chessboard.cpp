#include <bits/stdc++.h>
using namespace std;

int n,m;
int getAns(int n,int m){
    int ans = 2;
    int half = 2;
    if (n < 2 || m<2){
        return 0;
    }
    if (m == n && m+n == m*m/4){
        return m/2;
    }
    int check1 = m > n ? n:m;
    bool check2 = m==n;
    while(half < n && half < m){
        ans+=1;
        int area = ans*ans;
        half = area/2;
    }
    if (check1 % 2 != 0 || check2) ans -= 1;
    return ans;
}
int main(){
    cin >> n >> m;
    int ans = getAns(n,m);
    cout<<ans;
}