#include <iostream>
#include <stack>
using namespace std;
long long minHeight(long long *hist,long long start,long long end){
    long long minHeight = hist[start];
    for (int i =start;i<=end;i++){
        if (hist[i] < minHeight){
            minHeight = hist[i];
        }
    }
    return minHeight;
}
long long isMax(long long a,long long b){
    return a > b?a:b; 
}
long long maxHist(long long *hist,long long n){
    long long maxArea = 0;
    for (int i =1;i<=n;i++){
        for (long long j = i; j<=n;j++){
            long long height = minHeight(hist,i,j);
            long long area = (j - i + 1)*height;
            maxArea = isMax(maxArea,area);

        }
    }
    return maxArea;
}//O(n3)
long long maxHist2(long long *hist,long long n){
    long long maxArea = 0;
    for (int i =1;i<=n;i++){
        long long minHeightCurrent = hist[i];
        for (long long j = i; j<=n;j++){
            if (hist[j] < minHeightCurrent){
                minHeightCurrent = hist[j];
            }
            long long area = (j - i + 1)*minHeightCurrent;
            // cout<<area << " ";
            maxArea = isMax(maxArea,area);
            // cout<<maxArea<<" ";

        }
    }
    return maxArea;
}//O(n2) phai de long long
// template <class RandomIt>
// long long maxHist3(long long *hist,long long n){
//  return;
// }//lay mot cot lam tam -> dich ra trai va phai. Luu gia tri ung voi tung o. Neu ma o sau cao hon o truoc thi -> cho vao stack
long long maxHist4(long long *hist,long long n){
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
int main(){
    long long n;


    while (1){
        cin >> n;
        if (n==0) break;
        long long hist[n+1];
        for (int i =1;i<=n;i++){
            cin >> hist[i];
        }
        long long res = maxHist4(hist,n);
        cout << res<<endl;
    }
    
}