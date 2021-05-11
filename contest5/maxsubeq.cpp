#include <bits/stdc++.h>
using namespace std;
int A[1000000];
int maxSubSequence(int a[],int n){
    int max_current = A[0];
    int max_so_far = A[0];
    for(int i = 1;i<n;i++){
        max_current = max(max_current+A[i],A[i]);
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
    int res = maxSubSequence(A,n);
    if(res % 2 == 0){
        cout<<res;
    } else{
        cout<<"NOT_FOUND";
    }
    // cout << maxSubSequence(A,n) <<endl;

}