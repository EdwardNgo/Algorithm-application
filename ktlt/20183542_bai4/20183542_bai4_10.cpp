// Xây dựng một máy tìm kiếm (search engine) đơn giản.

// Cho  N  văn bản và  Q  truy vấn. Với mỗi truy vấn, cần trả về văn bản khớp với truy vấn đó nhất.

// Sử dụng phương pháp tính điểm TF-IDF:

// f(t,d)  là số lần xuất hiện của từ  t  trong văn bản  d 
// maxf(d)  là giá trị lớn nhất của  f(t,d)  với mọi  t 
// df(t)  là số văn bản chứa từ  t 
// TF(t,d)=0.5+0.5⋅f(t,d)maxf(t,d) 
// IDF(t)=log2(Ndf(t)) 
// Điểm số của từ  t  trong văn bản  d  là  score(t,d)=TF(t,d)⋅IDF(t) , nếu từ  t  không xuất hiện trong văn bản  d  thì  score(t,d)=0 .
// Điểm số của văn bản  d  đối với truy vấn gồm các từ (có thể trùng nhau)  t1,t2,...,tq  là  ∑qi=1score(ti,d) 
// Ta coi văn bản có điểm số càng cao thì càng khớp với truy vấn.

// Input:

// Dòng đầu tiên chứa số  N 
// Dòng thứ  i  trong  N  dòng tiếp theo thể hiện văn bản  i , mỗi dòng là một dãy các từ ngăn cách nhau bởi dấu phẩy
// Dòng tiếp theo chứa số  Q 
// Dòng thứ  i  trong  Q  dòng tiếp theo thể hiện truy vấn thứ  i , mỗi dòng là một dãy các từ ngăn cách nhau bởi dấu phẩy
// Output: Gồm  Q  dòng, dòng thứ  i  là chỉ số của văn bản khớp với truy vấn thứ  i  nhất. Nếu có nhiều văn bản có điểm số bằng nhau, in ra văn bản có chỉ số nhỏ nhất.

// CPP program to illustrate the 
// list::end() function 
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    // Creating a list 
    list<int> demoList; 
  
    // Add elements to the List 
    demoList.push_back(10); 
    demoList.push_back(20); 
    demoList.push_back(30); 
    demoList.push_back(40); 
  
    // using end() to get iterator  
    // to past the last element 
    list<int>::iterator it = demoList.end(); 
  
    // This will not print the last element 
    cout << "Returned iterator points to : " << *it << endl; 
  
    // Using end() with begin() as a range to 
    // print all of the list elements 
    for (auto itr = demoList.end(); 
         itr != demoList.begin(); itr--) { 
        cout << *itr << " "; 
    } 
  
    return 0; 
}