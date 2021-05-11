#include <iostream>
using namespace std;
#include <cmath>

//mang luu cac gia tri
int a[20];
bool isPossible(int x1,int y1){
    //i la hang tuong
    for (int i = 1;i<x1;i++){
        //check cot co trung va duong cheo co trung khong
        if(a[i] == y1 || abs(a[i] - y1) == abs(i-x1)){
            return false;
        }
    }
    return true;
}
void print(int n){
    for (int i = 1;i<=n;i++ ){
        cout << a[i] << " ";
    }
    cout<<endl;
}
void Try(int i,int n){
    for (int j = 1;j<=n;j++){
        if(isPossible(i,j)){
            a[i] = j;
            if(i==n) print(n);
            Try(i+1,n);
        }
    }
}

int main(){
    int n = 8;
    Try(1,n);
}