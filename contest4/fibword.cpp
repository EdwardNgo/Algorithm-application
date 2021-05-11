#include <bits/stdc++.h>
using namespace std;
string fibword(int i){
    if (i == 0 ) return "0";
    else if (i == 1) return "1";
    else return fibword(i-1) + fibword(i-2);
}//vet can 0()
//thuat toan 2 dem so lan p xuat hien trong f[i] voi i nho, khi do so phep so sanh rat it
//dem so lan xuat hien cua p o dona giua xau

int main(){//cai subtr(pos,chieu dai) chu khong phai la substr(pos1,pos2)
    string pattern;
    int n;
    cin >> n >> pattern;
    int count = 0;
    string bifib = fibword(n);
    cout<<bifib<<endl;
    int ptlen = pattern.length();
    int strlen = bifib.length();
    // for(long long i = 0;i < strlen;i++){
    //     // for(long long j = i;j < strlen;j++){
    //     //     string substr = bifib.substr(i,j);
    //     //     if (substr == pattern) {
    //     //         cout<< i<<" "<<j<<endl;
    //     //         count++;
    //     //     }
    //     // }
    //     // cout<<ptlen;
    //     string substr1 = bifib.substr(i,i+ptlen-1);
    //     cout<<substr1<<" "<<i<<" "<<i+ptlen-1<<endl;
    //     if(substr1 == pattern) {
    //         count++;
    //     }
    // }
    cout<<bifib.substr(3,4);
    // cout << count << endl;
}