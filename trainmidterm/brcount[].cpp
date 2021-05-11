#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[10000] = {0};
int lengthStr;
string bracket = "()";
int res = 0;
void input(){
    cin >> s;
    lengthStr = s.length();
}
void solution(){
    if (cnt[lengthStr]  == 0){
        // cout<<s<<cnt[lengthStr]<<endl;
        res ++;
    }
}
void _try(int i){
    char temp = s[i];
    if(s[i] == '?'){//neu la ? thi dien 1 trong 2
        for(int j = 0;j<=1;j++){

            s[i] = bracket[j];
            if(s[i] == bracket[0]){
                cnt[i+1] = cnt[i] + 1;
            }else if (s[i] == bracket[1]){
                cnt[i+1] = cnt[i] - 1;
            }
            if(i == lengthStr - 1) {
                solution();
            }
            else if (cnt[i+1]>=0){
                _try(i+1);}
            s[i] = temp;
        }
    }else{
        if(s[i] == bracket[0]){
            cnt[i+1] = cnt[i] + 1;
        }else if (s[i] == bracket[1]){
            cnt[i+1] = cnt[i] - 1;
        }
        if(i == lengthStr - 1) {
            solution();
        }
        else if (cnt[i+1]>=0){
            _try(i+1);}
    }
  
}

int main(){
    input();
    _try(0);
    cout<<res;
}