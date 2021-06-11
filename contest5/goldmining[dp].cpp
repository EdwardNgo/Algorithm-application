#include <bits/stdc++.h>
using namespace std;
#include <stack>
// khi chon nha kho x thi chi quan tam la luong vang lon nhat cua cac nha kho ma chon duoc truoc nha kho x
int n, l1,l2;
int a[100005];
int f[100005];
int res = 0;
void input(){
    cin >> n >> l1 >> l2;
    for (int i = 1;i<=n;i++){
        cin >> a[i];
    }
}
int _try(int x){
    if (x<0){
        return 0;
    }
    if (f[x] < 0){
        int tmp = 0;
        for(int i = x- l2;i<=x-l1;i++){
            tmp = max(tmp,_try(i));
        }
        f[x] = tmp+ a[x];
    }
    return f[x];
}

int main(){
    input();
    // // cout<<f[1];
    // for (int i =0;i<n;i++){
    //     f[i] = -1;
    // }
    // for(int i = n-l1;i<=n;i++){
    //     res = max(res,_try(i));
    // }
    // cout<<res;
    // for ( int i = 1; i <= l1 ; i ++) {
    //     f[i] = a[i];
    // }
    // for ( int i = l1 + 1 ; i <= n ; i ++) {
    //     for ( int j = i - l2  ; j <= i - l1  ; j ++) {
    //         f[i] = max ( f[i] , f[j] + a [ i ]);
    //     }
    // }
    for(int i = 1;i<=n;i++){
        f[i] = a[i];
        int s = max(0,i-l1);
        int e = max(0,i-l2);//khoang cach xa nhat
        for(int j = e;j<=s;j++){
            f[i] = max(f[i],f[j] + a[i]);
        }
    }
    cout<<*max_element(f,f+n);
}