#include <iostream>
#include <algorithm>
using namespace std;
// int max(int *a,int b,int c){
//     int result=0;
//     for(int i=b;i<=c;i++){
//         if (a[i]>result ) result=a[i];
//     }
//     return result;
// }
// int signal(int *arr,int b,int n){
//     int res = -1;
//     for (int i=1;i<n-2;i++){
//         int max1 = max(arr,0,i-1);
//         int max2 = max(arr,i+1,n-1);
//         if ((max1 - arr[i]) >= b and (max2 - arr[i]) >= b){
//             res =  (max1 - arr[i]) + (max2 - arr[i]);
//             break;
//         }

//     }
//     return res;
// }//0(n2) - 25 diem
long long max(long long a, long long b){
    return a > b ? a : b;
}
long long signal2(int *arr,int b,int n){
    int maxPreFix[n+1];
    int maxSuffix[n+1];
    maxPreFix[0] = -100000;
    maxSuffix[n+1] = -100000;
    for (int i = 1; i <= n; i++){
        maxPreFix[i] = maxPreFix[i-1] > arr[i] ? maxPreFix[i-1] : arr[i];
    }
    for (int i = n; i >=1;i--){
        maxSuffix[i] = maxSuffix[i+1] > arr[i] ? maxSuffix[i+1]: arr[i];
    }
    long long res = -1;
    for (int i = 2;i<=n;i++){
        if ((maxPreFix[i-1] - arr[i]) >= b and (maxSuffix[i+1]- arr[i]) >= b){
            // cout << maxPreFix[i-1] << " " << maxSuffix[i+1]<<" "<<arr[i]<<endl;
            res = max((maxPreFix[i-1] - arr[i]) +(maxSuffix[i+1]- arr[i]),res);
        } 
    }
    return res;
}//0(n2) diem cat la cai gia tri loang ngoang kia lon nhat

int main() {
    int n,b;
    cin >> n >> b;
    int arr[n];
    for (int i = 1; i <= n;i++){
        cin >> arr[i];
    }
    // int res = signal(arr,b,n);
    long long res2 = signal2(arr,b,n);
    cout << res2 << endl;
}