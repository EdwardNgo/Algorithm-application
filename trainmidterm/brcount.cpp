#include <bits/stdc++.h>
using namespace std;
string s;
int cnt = 0;
int l[1000];//tinh so ngoac trai lien tiep
int r[1000];//tinh so ngoac phai lien tiep
int lengthStr;
string bracket = "()";
void input(){
    cin >> s;
    lengthStr = s.length();
}
bool check(int i,int j){

    if( l[i-1] == r[i-1] && l[i-1] !=0){//neu so ngoac trai lien tiep truoc do dang bang so ngoac phai
        if(bracket[j]==')') return false;
        else return true;
    }
    if(r[i-1] >= lengthStr/2 && j == 1) return false;//neu truoc do so ngoac phai lien tiep da qua gioi han thi khong duoc dien tiep ngoac phai
    return true;
}
void solution(){
    cnt++;
    for(int i = 0;i<lengthStr;i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
void _try(int i){
    
    if (s[i] != '?' && i != lengthStr - 1 ){
        if( i != 0){
            if(s[i] == ')'){
                r[i] = 0;
                l[i] = l[i-1] + 1;
            } else if(s[i] == '('){
                l[i] = 0;
                r[i] = r[i-1] + 1;
            }
        }else if( i==0){
            if(s[i] == ')'){
                r[i] = 0;
                l[i] = 1;
            } else if(s[i] == '('){
                l[i] = 0;
                r[i] = 1;
        }
        }
        _try(i+1);
    } else if(s[i] != '?' && i == lengthStr - 1){
        solution();
    }
    else{
        for(int j = 0;j<=1;j++){//ngoac trai- ')':1 hoac ngoac phai - '(':0
            bool checked = check(i,j);
            if(checked){
                s[i] = bracket[j];
                if(bracket[j] == '(' ){
                    r[i] = 0;
                    l[i] = l[i-1] + 1;
                } else if(bracket[j] == ')' ){
                    l[i] = 0;
                    r[i] = r[i-1] + 1;
                }
            }
            if(i == lengthStr-1) solution();
            else _try(i+1);
        }
    }
}

int main(){
    input();
    // bool a = s[0] != '?' && 0 !=8;
    // cout<<a;
    // cout<<s[0];
    _try(0);
    cout<<cnt;
}
