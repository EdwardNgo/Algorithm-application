#include <bits/stdc++.h>
using namespace std;
int n;
struct period{
    int start;
    int end;
    int duration;
};
int res = 0;
int maxRes = INT_MIN;
struct period p[2000000];
bool compare(period a,period b){
    return a.end<b.end;
}
void input(){
    cin>>n;
    for(int i = 0;i<n;i++){
        int temp1,temp2;
        cin >> temp1 >>temp2;
        p[i].start = temp1;
        p[i].end = temp2;
        p[i].duration = temp2-temp1;
    }
    sort(p,p+n,compare);
}
void solution(){
    for (int i = 0;i<n;i++){
        res = p[i].duration;
        for(int j = 1;j<n;j++){
            if(p[j].start >= p[i].end){
                res+=p[j].duration;
                maxRes = max(maxRes,res);
                res = p[i].duration;
            }
        }
    }

}
int main(){
    input();
    solution();
    cout<< maxRes << endl;
}