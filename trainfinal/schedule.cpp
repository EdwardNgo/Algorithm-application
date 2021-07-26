#include <bits/stdc++.h>
using namespace std;
int n,q = INT_MIN;
int d[16];
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> d[i];
    }
    sort(d,d+n);
    for(int i = 0;i<n;i++){
        cout <<d[i];
    }
    while(next_permutation(d,d+n)){
        int count = 1;
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=d[i];
            if(sum >= 6) {
                count++;
                sum = 0;
            }
        }
        q = max(count,q);
    }
    cout<<q;
}