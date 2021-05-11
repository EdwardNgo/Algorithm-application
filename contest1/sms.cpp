#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
map <char,int> letter_map = {{'a',1},{ 'b',2},{ 'c',3},{'d',1},{'e',2},{ 'f',3},{'g',1},{ 'h',2},{ 'i',3},{'j',1},{'k',2},{'l',3},{'m',1},{'n',2},{'o',3},{'p',1},{'q',2},{'r',3},{'s',4},{'t',1},{'u',2},{'v',3},{'w',1},{'x',2},{'y',3},{'z','4'},{' ',1}};

int main(){
    int n;
    scanf("%d\n", &n);
    for (int i=0;i < n;i++){
        string str;
        getline(cin,str);
        // a.push_back(pressNum(str));
        int res = 0;
        for (int i = 0; i < str.length();i++){
            // cout<<letter_map[str[i]]<<endl;
            res += letter_map[str[i]];
        }        
        cout << "Case #"<<i+1<<": "<<res <<endl;

    }

}