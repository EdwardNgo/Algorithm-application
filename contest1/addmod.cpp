#include <iostream> 

using namespace std;

int main(){
    unsigned long long a,b;
    const unsigned int c = 1000000007;
    cin >> a >>b;
    cout <<(unsigned long long)(a%c+b%c)%c; 

    return 0;
}