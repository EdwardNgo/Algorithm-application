#include <iostream>
using namespace std;
long long n,m;
long long tree[1000005];

long long maxHeight(long long *tree,long long n){
    long long maxtree = tree[1];
    for (int i = 1;i<=n;i++){
        if(tree[i] > maxtree){
            maxtree = tree[i];
        }
    }
    return maxtree;
}
long long minHeight(long long *tree,long long n){
    long long mintree = tree[1];
    for (int i = 1;i<=n;i++){
        if(tree[i] < mintree){
            mintree = tree[i];
        }
    }
    return mintree;
}
long long totalMeters(long long height){
    long long sum = 0;
    for(int i = 1;i<=n;i++){
        if(tree[i] > height){
            sum += tree[i] - height;
        }
    }
    return sum;
}
long long cut(long long *tree,long long n,long long low,long long high,long long m){
    long long mid = (low+high)/2;
    long long total = totalMeters(mid);
    if(high - low == 1 || total == m){
        return mid;
    } else{
        if(totalMeters(mid) < m) {
            return cut(tree,n,low,mid,m);
        } else{
            return cut(tree,n,mid,high,m);
        }
    }

}
int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i ++ ){
        cin>>tree[i];
    }
    long long low = 1;
    long long high = 1000000007;
    long long mid = 0;

    while ((high-low)>0){
    //cout<< " da vao while";
        long long mid=(high+low+1)/2;
        if(totalMeters(mid)>=m){
            low=mid;
        }else{
            high=mid-1;
        }
    }
    cout<<low;

    // }
    // cout << cut(tree,n,low,high,m) << endl;
}