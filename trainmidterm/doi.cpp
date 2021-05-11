#include <bits/stdc++.h>
using namespace std;
int n;
int p[1000000];
bool hillFound = false;
bool valleyFound = false;
// int valleyLeft ,hillLeft;
// int valleyRight,hillRight;
int maxHill = INT_MIN;
int maxValley = INT_MIN;
int right_valley[1000000];
int left_valley[1000000];
int left_hill[1000000];
int right_hill[1000000];
void input(){
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> p[i];
    }
}
void solution(){
    for(int i = 2;i<n;i++){
        int valleyLeft ,hillLeft = 0;
        int valleyRight,hillRight = 0;
        if(p[i] > p[i+1] && p[i] >p[i-1] ){
            // cout<<"hill"<<i<<endl;
            hillFound = true;
        }
        else if(p[i] < p[i+1] && p[i] < p[i-1]){
            // cout<<"val"<<i<<endl;
            valleyFound = true;
        }
        for(int j = i;j > 1;j--){
            if(hillFound){
                if(p[j] > p[j-1]){
                    hillLeft = j - 1;
                } else{
                    hillLeft = j;
                    break;
                }
            }
            if(valleyFound){
                if(p[j] < p[j-1]){
                    valleyLeft = j - 1;
                } else{
                    valleyLeft = j;
                    break;
                }
            }
        }
        for(int j = i;j < n;j++){
            if(hillFound){
                if(p[j] > p[j+1]){
                    hillRight = j + 1;
                } else{
                    hillRight = j;
                    break;
                }
            }
            if(valleyFound){
                if(p[j] < p[j+1]){
                    valleyRight = j + 1;
                } else{
                    valleyRight = j;
                    break;
                }
            }
        }
        if(hillFound) {
            // cout<<hillLeft<<hillRight<<i;
            int hillHeight = min(i- hillLeft,hillRight-i);
            maxHill = max(hillHeight,maxHill);
        }
        if (valleyFound) {
            // cout<< valleyLeft<<" "<<valleyRight<<endl;
            int valleyHeight = min(i - valleyLeft,valleyRight-i);
            maxValley = max(maxValley,valleyHeight);
        }
        valleyFound = false;
        hillFound = false;
    }
}//0(n2) -> 50
void solution2(){
    p[0] = p[1];
    for(int i = 1;i<=n;i++){
        if(p[i] > p[i-1]) left_hill[i] = left_hill[i-1] + 1;
        if(p[i] < p[i-1]) left_valley[i] = left_valley[i-1] + 1;
    }
    for(int i = n-1;i>=1;i--){
        if(p[i] > p[i+1]) right_hill[i] = right_hill[i+1] + 1;
        if(p[i] < p[i+1])  right_valley[i] = right_valley[i+1] + 1;
    }
    for(int i = 1;i< n;i++){
        maxHill = max(maxHill,min(right_hill[i],left_hill[i]));
        maxValley = max(maxValley,min(right_valley[i],left_valley[i]));
    }

}//0(n) luu gia tri vao cac mang trai phai cua thung lung roi so sanh o tung diem
int main(){
    input();
    solution2();
    if(maxHill == INT_MIN) maxHill = 0;
    if(maxValley == INT_MIN) maxValley =0;
    cout<< maxHill<<" "<<maxValley;
}