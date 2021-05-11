#include <bits/stdc++.h>
using namespace std;

int A[10000];
int lis[10000];

int _lis(int n,int a[]){
    lis[0] = 1;
    for (int i = 1;i<n;i++){
        lis[i] = 1;
        for(int j = 0;j<i;j++){
            if(a[i] > a[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            }
        }
    }

    return *max_element(lis,lis+n);
}
int lis2(int n,int a[]){
    int result = 1;
    for (int i=1; i<=n; i++) {
        f[i] = 0;
        for (int j=0; j<i; j++) if (a[j] < a[i]) {
            f[i] = max(f[i], f[j] + 1);
        }
        result = max(result, f[i]);
    }
    return result
}

int main(){
    int n;
    cin >> n;
    for (int  i = 0; i < n;i++){
        cin>>A[i];
    }

    cout << _lis(n,A) <<endl;

}