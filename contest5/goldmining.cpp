#include <bits/stdc++.h>
using namespace std;
#include <stack>

int n, l1,l2;
int a[100005];
bool visited[100005] = {false};
int pos[100005];
stack<int> s;
int max_gold = INT_MIN;
int current_gold[100005];
void input(){
    cin >> n >> l1 >> l2;
    for (int i = 1;i<=n;i++){
        cin >> a[i];
    }
}
bool check(int i,int j){
    if(j == 0) return false;
    if(j == 1){
        if(!s.empty()){
            return true;
        }
        if(i - s.top() >= l1 && i - s.top() <= l2 && s.top() != 0){
            return true;
        }

    }
    return false;
}
void solution(){
    s.pop();
    for(int i = 1;i<=n;i++){
        // cout<<current_gold[i];
        max_gold = max(max_gold,current_gold[i]);
    }
    // cout<<endl;

}
void _try(int i){
    for (int j = 1;j>=0;j--){
        if(check(i,j)){
            // cout<<s.top();
            // cout<<i;
            int last;
            if (!s.empty())  last = s.top();
            else last = 0;
            current_gold[i] = current_gold[last] + a[i];
            s.push(i);
        } 
        if(i == n ) solution();
        else _try(i+1);
    }
}
int main(){
    pos[0] = 0;
    current_gold[0] = 0;
    input();
    _try(1);
    // for(int i = 1;i<=n;i++){
    //     cout<<pos[i]<<" ";
    // }
    cout<< s.size();
    cout<<s.top();
    cout<<max_gold;
}
