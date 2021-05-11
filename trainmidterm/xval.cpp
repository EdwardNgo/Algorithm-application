#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int x = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        string cmd;
        getline (cin, cmd);
        if(cmd.compare("++X") == 0 || cmd.compare("X++") == 0){
            x++;
        } else if (cmd.compare("--X") == 0 || cmd.compare("X--") == 0){
            x--;
        }
    }
    cout<<x;
}