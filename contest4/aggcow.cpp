#include <bits/stdc++.h>
using namespace std;
int t;
int n,c;
int x[100007];
int s[100007];//luu gia tri con bo o chuong nao

bool check(int d){//ham check xem voi khoang cach nay co cho loi giai khong
    s[1] = 1;//con bo dau tien o chuong 1
    for(int i = 2;i<=c;i++){
        s[i] = -1;//may con bo tiep theo chua cho vao chuong nao
        int k = s[i-1];
        for(int j =k;j<=n;j++){
            if(x[j] - x[k] >=d){
                s[i] = j;//gan con bo thu i vao chuong j
                break;
            }
        }
        if(s[i] == -1){
            return false;
        }
    }
    return true;
}
int solution(){
    int minD = 0;
    int maxD = x[n] - x[1];
    int res = 0;
    while(minD<=maxD){
        int d = (minD+maxD)/2;
        if(check(d)){
            res = d;
            minD = d+1;
        }else{
            maxD = d-1;
        }        
    }
    return res;
}
void input(){
    cin >> t;
    while (t--){
        cin>>n>>c;
        for(int i = 1;i<=n;i++){
            cin >> x[i];

        }
        sort(x+1,x+n+1);
        cout<<solution()<<endl;
    }

}
int main(){
    //them cai ios bae voi cin.tie
    input();
}