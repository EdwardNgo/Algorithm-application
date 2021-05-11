#include <bits/stdc++.h>
using namespace std;
int t;
long long X[1005];
long long Y[1005];
int n;//so chieu cua vecto X,Y
long long res = 0;
int minRes = INT_MAX;
int count = 0;
// long long factory(long long i){
//     if (i == 0 || i == 1)  return 1;
//     else return i*factory(i-1);
// }
//tai sao yeu cau giu nguyen X ma van duoc sap xep-> luc sap xep hoan vi cho Y se co truong hop min, tai do minY se cung vi tri voi maxX .....
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
        sort(Y,Y+n,greater<int>());//sap xep day Y giam dan
        sort(X,X+n);//sap xep day X tang dan -> tvh min

        for(int j = 0;j<n;j++){
            res += X[j]*Y[j];
        }
        // if (res < minRes){
        //     minRes = res; 
        // }
        // next_permutation(Y,Y+n);

        cout<<"Case #"<<i+1<<": "<<res<<endl;
        res = 0;

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