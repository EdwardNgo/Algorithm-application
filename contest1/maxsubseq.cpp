#include <iostream>
using namespace std;
// int maxEle(int *a,int n){
    
//     int maxNum = 0;
//     int sumFull = 0;
//     for (int i = 1;i <= n;i++){
//         sumFull += a[i];
//         int sumSub = 0;
//         for (int j = i+1;j <= n;j++){
//             sumSub += a[j];
//             // cout << sumSub << endl;
//             if (sumSub > maxNum) maxNum = sumSub;
//         }
//         if(sumFull > maxNum) maxNum = sumFull;
//         // cout << "hi-"<<maxNum << endl;
//     }
//     return maxNum;
// } 0(n2) -> cai tien ?? cong'kenh'
long long algo2(int *a,int n){
    long long max = a[0];
    for (int i =0;i<n;i++){
        int s = 0;
        for (int j =i;j<n;j++){
            s = s + a[j];
            if (s > max) max = s;
        }
    }
    return max;
}
int maxElementDp(int *a,int n){
    int max_so_far = a[1];
    int curr_max = a[1];
    for (int i = 2;i<=n;i++){
        curr_max = a[i] > a[i] + curr_max ? a[i] : a[i] + curr_max;
        max_so_far = curr_max > max_so_far ? curr_max : max_so_far;
    }
    return max_so_far;
}


int main(){
    int n;
    cin >>n;
    int arr[n+1];
    for (int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    cout << (maxElementDp(arr,n));
    // for (int i = 1;i <= n;i++){
    //     cout <<arr[i];
    // }
}