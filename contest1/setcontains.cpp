

#include <bits/stdc++.h>
#include <bitset>
using namespace std;
 bool isSubset(int arr1[], int arr2[],
              int m, int n)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (arr2[i] == arr1[j])
                break;
        }
 
        /* If the above inner loop was
        not broken at all then arr2[i]
        is not present in arr1[] */
        if (j == m)
            return 0;
    }
 
    /* If we reach here then all
    elements of arr2[] are present
    in arr1[] */
    return 1;
}
int main()
{
    // code
    int a,b;
    cin >> a;
    int m,n;
    int arr1[a+1];
    for (int i = 0;i<a;i++){
        cin >>arr1[i];
    }
    m = 1 << arr1[0];
    for (int i = 1;i<a;i++){
        m = (m | 1<<arr1[i]);
    }
    cin >> b;
    int arr2[b+1];
    for (int i = 0;i<b;i++){
        cin >>arr2[i];
    }
    n = 1 << arr2[0];
    for (int i = 1;i<b;i++){
        n = (n | 1 << arr2[i]);
    }
    // cout<<bitset<32>(m)<<" "<<m<<endl;
    // cout<<bitset<32>(n)<<" "<<n<<endl;
    // cout<< bitset<32>(m) & bitset<32>(n) <<endl;
    // if (n & m){
    //     cout << 1;
    // } else{
    //     cout << 0;
    // }
    cout << isSubset(arr1,arr2,a,b);
    // cout<<30 &&992;
    // int m = sizeof(arr1) / sizeof(arr1[0]);
    // int n = sizeof(arr2) / sizeof(arr2[0]);
    // if (n>m){
    //     cout << 0;
    //     return 0;
    // }
    // unordered_set<int> s;
    // for (int i = 0; i < m; i++) {
    //     s.insert(arr1[i]);
    // }
    // int p = s.size();
    // for (int i = 0; i < n; i++) {
    //     s.insert(arr2[i]);
    // }
    // if (s.size() == p) {
    //    cout << 1;
    // }
    // else {
    //     cout << 0;
    // }
    return 0;
}