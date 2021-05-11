#include<bits/stdc++.h>
using namespace std;

long long n,m;   // lay >=m
long long h[1000005];

long long H=0;// tim nhat cat
//int hMAX=0;

long long Thetich(int H){  // tra ve the tich  >= H
    long long res=0;

    for (int i=0;i<n;i++){
        if(h[i]-H>0){
            res+=h[i]-H;
        
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n>>m;
    //h=new int[n];    // luu tru chieu cao cua cay tiu 1..n
    for(int i=0;i<n;i++){
        cin>> h[i];
        //if(h[i]>hMAX) hMAX=h[i];
    }


    long long low=1,high=1000000007;

    while ((high-low)>0){
        //cout<< " da vao while";
        long long mid=(high+low+1)/2;
        if(Thetich(mid)>=m){
            low=mid;
        }else{
            high=mid-1;
        }
    }
    cout<<low; 


}

