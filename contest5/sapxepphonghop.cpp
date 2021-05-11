#include <bits/stdc++.h>
using namespace std;
struct meeting {
    int start;
    int end;
    int pos;   
};
struct meeting meets[100];
bool compare(meeting m1,meeting m2){
    return (m1.end<m2.end);
}
void max_meeting(int s[],int f[],int n){//s la mang luu thoi gian bat dau cac cuoc hop, f la mang luu thoi gian ket thuc
    for(int i = 0;i<n;i++){
        meets[i].start = s[i];
        meets[i].end = f[i];
        meets[i].pos = i+1;
    }
    sort(meets,meets+n,compare);
    vector<int> m;//luu vi tri cac cuoc hop se duoc chon
    m.push_back(meets[0].pos);//luu cuoc hop dau lun 
    int time_limit = meets[0].end;
    for(int i = 1;i<n;i++){
        if(meets[i].start >= time_limit){
            m.push_back(meets[i].pos);
            time_limit = meets[i].end;
        }
    }
    for (int i = 0; i < m.size(); i++) {
        cout << m[i] << " ";
    }
}
int main()
{
    // Starting time
    int s[] = { 1, 3, 0, 5, 8, 5 };
     
    // Finish time
    int f[] = { 2, 4, 6, 7, 9, 9 };
     
    // Number of meetings.
    int n = sizeof(s) / sizeof(s[0]);
 
    // Function call
    max_meeting(s, f, n);
 
    return 0;
}