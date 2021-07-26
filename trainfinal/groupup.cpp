#include <bits/stdc++.h>
using namespace std;
int n;
// int a[100005];
vector<int> a;
int A[100005];
int totalTime = 0;
void input(){
    cin>>n;
    // a.resize(n+1);
    for(int i = 0;i<n;i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
        A[i] = temp;
    }
}
void solution(){
    // vector<int> transform;

    while(n > 0){
        cout<<n;
        int maxT = INT_MIN;
        if(n%2==0){
            for(int i = 0;i<=n/2;i++){
                a[i] = a[i*2] + a[i*2+1];
                maxT = max(maxT,a[i]);
            }
        }else{
            for(int i = 0;i<n/2+1;i++){
                a[i] = a[i*2] + a[i*2+1];
                maxT = max(maxT,a[i]);
            }
            a[n/2+1] = a[n-1];
        }
        cout<<maxT<<endl;
        totalTime += maxT;
        n = n/2;
    }
}
int main(){
    input();
    solution();
    cout<<totalTime;
}