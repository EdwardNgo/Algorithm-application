#include <bits/stdc++.h>
using namespace std;
int t;
int X[1000];
int Y[1000];
int n;//so chieu cua vecto X,Y
int res = 0;
int minRes = INT_MAX;
int count = 0;
long long factory(long long i){
    if (i == 0 || i == 1)  return 1;
    else return i*factory(i-1);
}
void input(){
    cin >>t;
}

void solution(){
    for(int i = 0;i<t;i++){//t testcases
        cin>>n;
        for(int j = 0;j<n;j++){
            cin >>X[j];
        }
        for(int j = 0;j<n;j++){
            cin >>Y[j];
        }
        long long numOfPermutations = factory(n);
        while(numOfPermutations>0){
            for(int j = 0;j<n;j++){
                res += X[j]*Y[j];
            }
            if (res < minRes){
                minRes = res; 
            }
            numOfPermutations--;
            next_permutation(Y,Y+n);
            res = 0;
        }
        cout<<"Case #"<<i+1<<": "<<minRes<<endl;
        minRes = INT_MAX;
    }
}
int main(){
    input();
    solution();
    // input();
    // solution();
    // for(int i = 0;i<t;i++){
    //     cout<<"Case #"<<i+1<<": "<<minRes[i];
    // }

}