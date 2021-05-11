#include<bits/stdc++.h>
using namespace std;
const int MAX = 10005;
const double PI = atan(1)*4;

int N, F;
int cnt = 1e9;
int r[MAX];
double S[MAX];
double maxS;

void input(){
    cin >> N >> F;
    maxS = 0;
    for (int i = 0;i<N;i++){
        cin >> r[i];
        S[i] = r[i]*r[i]*PI;
        maxS = max(maxS,S[i]);
    }
}

bool calculatePeople(double m){
    int totalPeople = 0;
    for (int i = 0;i<N;i++){
        totalPeople += floor(S[i]/m);
    }
    return totalPeople > F;//tinh ca host nua ??? F+1 chu' nhi?

}

double getMaxPie(double left,double right){
    double mid = (left + right)/2.0;
    cnt--;

    if (right - left < 10e-7 || cnt < 0){
        return mid;
    }
    else {
        if (calculatePeople(mid)) {//cang ve left thi luong nguoi cang nhieu, neu o mid da lon hon thi can phai di ve right
            return getMaxPie(mid,right);
        } else {
            return getMaxPie(left,mid);
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T > 0){
        input();
        cout<<setprecision(6)<<fixed;
        cout<<getMaxPie(0,maxS)<<endl;//endl sau moi testcase
        // printf("%.6f\n",getMaxPie(0,maxS));
        T--;
    }
    return 0;
}