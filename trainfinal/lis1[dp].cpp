#include <stack>
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int n;
int a[1000001];
int maxA[1000000001];
int f[1000001];
int main(){
  cin >> n;
  int ans = 0;
  for(int i = 1;i<=n;i++){
    cin >> a[i];
  }
  for(int i = 1;i<=n;i++){
    maxA[a[i]] = max(maxA[a[i] - 1] + 1,maxA[a[i]]);
    // f[i] = maxA[a[i];
    ans = max(maxA[a[i]],ans);
  }
  cout<<ans;

}