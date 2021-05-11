#include <bits/stdc++.h>
using namespace std;
int A[1000000];
int maxEvenSubSequence(int A[],int n){
    int max_current = 0;
    int max_so_far = 0;
    int start = 0;
    for(int i = 0;i<n;i++){
        if (A[i] % 2 == 0){
            max_current = A[i];
            max_so_far = A[i];
            start = i+1;
        }
        break;
    }
    for(int i = start+1;i<n;i++){
        if(A[i]%2 == 0 && A[i-1]%2 != 0) {
            max_current = A[i];
        } else if(A[i]%2 == 0 && abs(A[i-1])%2 == 0){
            max_current = max(max_current+A[i],A[i]);
        }
        // cout<<max_current<<endl;
        max_so_far = max(max_current,max_so_far);
    }
    return max_so_far;
}
int main(){
    int n;
    cin >> n;
    for (int  i = 0; i < n;i++){
        cin>>A[i];
    }

    int res = maxEvenSubSequence(A,n);
    if(res == 0 ){
        cout<<"NOT_FOUND";
    } else{
        cout<<res;
    }
}