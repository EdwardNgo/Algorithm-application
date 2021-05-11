//n mon hoc va m giao vien , moi giao vien chi co the day cac mon trong danh sach cho truoc
//cac mon trung gio se k duoc day boi cung mot giao vien 
// tai cua mot giao vien la so khoa hoc giao vien phai day
//--> tim cach xep de tai cua giao vien co tai cao nhat la thap nhat

//check giao vien x co day giao vien y hay khong
#include <bits/stdc++.h>
using namespace std;
int m,n;//m la so giao vien, n la so mon
int numConflicts;
int conflict[30][30];
int teacher[11][31] = {0};//neu giao vien day mon nao thi la 1
int x[31];//giao vien day mon i
int teacherLoad[11] = {0};//tim max cai nay
int currentMaxLoad[31] = {0};
int maxLoad = INT_MAX;

void input(){
    cin >> m>>n;
    for (int i = 1;i<=m;i++){
        int numCourse;
        cin >> numCourse;
        for(int j = 0;j<numCourse;j++){
            int q;
            cin >> q;
            teacher[i][q] = 1;
        }
    }
    cin >> numConflicts;
    for (int i = 1; i<=numConflicts;i++){
        int temp1,temp2;
        cin >>temp1>>temp2;
        conflict[temp1][temp2] = conflict[temp2][temp1] = 1;
    }
}
bool check(int j,int i){//xem mon i co bi conflict voi giao vien j khong
    if (i == 1) return true;
    else {
        for(int k=1;k<i;k++){
            if(x[k] == j){//giao vien j day mon k
                if (conflict[j][i] == 1) return false;
            }
        }
    }
    return true;
}

int _try(int k){//try het cac mon
    for(int j = 1;j<=m;j++){//di het cac giao vien
        if(teacherLoad[j] + 1<maxLoad && teacher[j][k] == 1 && check(j,k)){
            x[k] = j;//mon k duoc giao vien j day
            teacherLoad[j]++;//so mon cua giao vien j
            if (k==n) {
                maxLoad = min(maxLoad,currentMaxLoad[k-1]);
            }
            else {
                currentMaxLoad[k] = max(currentMaxLoad[k-1],teacherLoad[j]);
                if (currentMaxLoad[k] < maxLoad) _try(k+1);
            }
            teacherLoad[j]--;
        }
    }
}
int main(){
    input();
    currentMaxLoad[0] = 0;
    _try(1);
    if(maxLoad == INT32_MAX){
        cout<<"-1";
    } else{
        cout<<maxLoad;
    }
}