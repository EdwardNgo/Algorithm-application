#include <bits/stdc++.h>
using namespace std;
int n;//so cua hang
int x[100000];//gia cua pepsi tai cua hang thu i
int q;//so ngay lien tiep dinh mua
int res[10000];
int main(){
    cin >>n;
    for (int i = 1;i<=n;i++){
        cin >> x[i];
    }
    cin >> q;
    for(int j = 1;j<=q;j++){
        int money,count=0;
        cin >>money;
        for(int i = 1;i<=n;i++){
            if (money >= x[i]){
                count++;
            }
        }
        res[j] = count;
    }
    for(int j = 1;j<=q;j++){
        cout<< res[j]<<endl;
    }

}