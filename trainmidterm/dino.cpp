#include <bits/stdc++.h>
using namespace std;
int n;
int p[10000];//mang luu may con khung long
string s;
queue<int> hallway;
stack<int> cage;


void input(){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> p[i];
    }
    for(int i = n-1;i>=0;i--){
        cage.push(p[i]);
    }
    cin >> s;
}
void solution(){
    int cmdLength = s.length();
    for(int i = 0;i<cmdLength;i++){
        if(s[i] == 'C'){
            if(!cage.empty()){
                int dino_to_hallway = cage.top();
                cage.pop();
                hallway.push(dino_to_hallway);
            }
        }else{
            if(!hallway.empty()){
                int dino_to_cage = hallway.front();
                hallway.pop();
                cage.push(dino_to_cage);
            }
        }
    }
}
int main(){
    input();
    solution();
    // cout<<cage.top();
    // cage.pop();
    // cout<<cage.top();
    // cage.pop();
    // cout<<cage.top();
    // cage.pop();
    // cout<<cage.top();
    // cage.pop();
    for(int j = 0;j<n;j++){
        cout<<cage.top();
        cage.pop();
    }
    return 0;
}