#include <bits/stdc++.h>
using namespace std;
int n,testcase;
long long a[100005];
long long dp[100005] = {1};//do dai day con dai nhat ket thuc o i
int  main(){
    cin >> testcase;
    while(testcase--){
        cin >> n;
        for(int i = 1;i<=n;i++){
            cin>>a[i];
            dp[i] = 1;
        }
        // dp[a[1]] = 1;
        long long ans;
        for(int i = 1;i<=n;i++){
            long long last = 0;
            for(int j = i;j>=1;j--){
                if(a[i]-a[j] == 1){
                   last = max(last,dp[j]);
                }
            }
            dp[i] += last;
        }
        for(int i = 1;i<=n;i++){
            cout<<dp[i]<<" ";
        }
        // cout<<ans;
    }
}
// void input(){
//     cin >> n;
//     for(int i = 1;i<=n;i++){
//         cin>>a[i];
//         if(pos.count(a[i])>0){
//             pos[a[i]].push_back(i);
//         }else{
//             vector<int> idx;
//             idx.push_back(i);
//             pair<long long,vector<int>> temp = make_pair(a[i],idx);
//             pos.insert(temp);
//         }
//     }
// }
// void solution(){
//     for(int i = 1;i<=n;i++){
//         for(int j = 0;j<pos[a[i]].size();j++){

//         }
//     }
// }