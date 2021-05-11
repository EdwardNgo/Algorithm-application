#include <bits/stdc++.h>
using namespace std;
int n;
string binary;
void printRes(){
    for (int i = 0;i<n;i++){
        cout<<binary[i];
    }
}
int main(){
    cin >> n;
    cin >> binary;
    int lastCharIndex = n-1;
    while(binary[lastCharIndex] == '1'){
        lastCharIndex--;
    }
    // cout<<lastCharIndex;
    if(lastCharIndex < 0){//111..111
        cout<<"-1";
        return 0;
    }else{
        // cout<<"hi";
        if (lastCharIndex == n-1){//...0
            binary[lastCharIndex] = '1';
        } else {//...011->...100
        // cout<<"ha";
            binary[lastCharIndex] = '1';
            for(int j = lastCharIndex+1;j<n;j++){
                binary[j] = '0';
            }
        }
    }
    printRes();
    return 0;
}