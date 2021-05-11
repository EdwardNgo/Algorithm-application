#include <iostream> 

using namespace std;

int main(){
    int n;
    unsigned long long sum = 0;
    const unsigned int c = 1000000007;
    cin >> n;
    for (int i = 0; i < n;i++){
        unsigned long long a;
        cin >> a;
        sum+=a;
    }
    cout <<(unsigned long long)(sum)%c; 

    return 0;
}