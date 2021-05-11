#include <bits/stdc++.h>
using namespace std;
//65 diem
struct item{
    int weight;
    int value;
};
int n,b;
int maxValue = INT_MIN;
int totalValue[101] = {0};
int totalWeight[101] = {0};
item item_list[101];
bool comp(item a, item b){
    if(float(a.value/a.weight) > float(b.value/b.weight)) return true;
    else return false;
}
void input(){
    cin >> n >>b;
    for(int i = 1;i<=n;i++){
        cin >> item_list[i].weight;
        cin >> item_list[i].value;
    }
    // sort(item_list+1,item_list+n+1,comp);
}
void solution(int i){
    int preValue = totalValue[i-1];
    maxValue = max(maxValue,preValue);
}
void solution2(){
    maxValue = max(maxValue,totalValue[n]);
}

void _try(int i){
    for(int j = 0;j<=1;j++){//lay hoac khong lay do vat
        if(j == 1){
            totalWeight[i] = totalWeight[i-1] + item_list[i].weight;
            totalValue[i] = totalValue[i-1] + item_list[i].value;
        }
        if(totalWeight[i] > b) solution(i);
        else if(i == n && totalWeight[i] <= b) solution2();
        else _try(i+1);
        if(j == 1){
            totalWeight[i] = totalWeight[i] - item_list[i].weight;
            totalValue[i] = totalValue[i] - item_list[i].value;
        }
    }
}

int main(){
    input();
    totalWeight[0] = 0;
    totalValue[0] = 0;
    _try(1);
    // for(int i = 1;i<=n;i++){
    //     cout<<totalWeight[]
    // }
    cout<<maxValue;
}