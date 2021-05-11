#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// template <class RandomIt>
// vector<int> calc(RandomIt first,RandomIt last){
//     vector<int> result;
//     stack<randomIt> s;
//     for (randomIt it= first; it != last; it++){
//         while(!s.empty() && *s.top() > *it) s.pop(); //s khong rong va s van lon hon cot ke tiep
//         result.push_back(it - (s.empty() ? first - 1:s.top()));
//         s.push(it);
//     }
//     return result;
// }
long long maxHist(long long *hist,long long n){
    stack<int> s;
    int tp;
    long long max_area = 0;
    long long area_with_top;
    int i =1;
    while (i <=n){
        if(s.empty() || hist[s.top()] <= hist[i]) s.push(i++);
        else{
            tp = s.top();
            s.pop();
  
            // Calculate the area with hist[tp] stack  
            // as smallest bar 
            area_with_top = hist[tp] * (s.empty() ? i :  i - s.top() - 1); 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        }
    }
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = hist[tp] * (s.empty() ? i :  
                                i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
}
int main() {
    long long n,test;


    while (1){
        cin >> n;
        if (n==0) break;
        long long hist[n+1];
        for (int i =1;i<=n;i++){
            cin >> hist[i];
        }
        long long res = maxHist(hist,n);
        cout << res<<endl;
    }
    
}
