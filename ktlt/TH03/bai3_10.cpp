
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

void printHamming(int N, int K)
{
    string str, curr;
    int j = N;
    while (j--)
    {
        str.push_back('0');
    }

    for (int i = N - 1; i >= N - K; i--)
    {
        str[i] = '1';
    }
    curr = str;
    do
    {
        cout << curr <<endl;
    } while (next_permutation(curr.begin(), curr.end()));

    cout << endl;
}
int main()
{
    int N, K,M;
    cin>>M;
    while(M--){
    cin >> N >> K;
    printHamming(N, K);
    
    }
}