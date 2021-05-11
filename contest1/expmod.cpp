#include <iostream> 

using namespace std;
const unsigned int c = 1000000007;

int expmod(unsigned long long a, unsigned long long b,unsigned int c){
    long res = 1;
    a = a%c;
    b = b%(c-1);
    while(b>0){
        if(b % 2 > 0){
            res = res*a%c;
        }
        a = a*a%c;
        b /= 2;
    }
    return int(res);

}
int main(){
    unsigned long long a,b;
    cin >> a >>b;
    cout <<expmod(a,b,c); 
    return 0;
}