#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#include <functional>

long long getMinDistance(map<long long,long long,greater<long long>> cus,long long n,long long k){
    long long total_dist = 0;
    long long remain = 0;// so hang con du
    long long current_dist = 0;
    for (const auto& detail:cus){
        long long x = detail.first;//vi tri
        long long m = detail.second;//khoi luong van chuyen
        m = m - remain;
        if (m < 0){// neu m < 0 tuc la van thua hang
            remain = -m;
            m = 0;
        }else{
            remain = m % k;
            if(remain !=0 ){
                remain = k - remain;
            }
            long long deliver_time;
            deliver_time = m/k;
            if (remain > 0){
                total_dist += 2*(deliver_time + 1)*x;
            }else{
                total_dist += 2*(deliver_time)*x;
            }
        }
    }

    return total_dist;
}
int main(){
    long long n,k;
    cin >> n >> k;
    map<long long,long long,greater<long long>> pos,neg;//sap xep giam dan key
    for (int i = 1; i <= n;i++){
        long long x,m;
        cin >> x >> m;
        // customer.insert(pair<long long,long long>(x,m));
        if(x > 0){
            pos.insert(pair<long long,long long>(x,m));
        } else{
            neg.insert(pair<long long,long long>(-x,m));
        }
    }
    cout<<getMinDistance(neg,n,k) + getMinDistance(pos,n,k);
    // cout<<getMinDistance(xNeg,mNeg,n,k);
    // cout<<getMinDistance(xNeg,mNeg,n,k);
}