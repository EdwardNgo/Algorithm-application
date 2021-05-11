#include <bits/stdc++.h>
using namespace std;
string fibword[100];
int n;
string p;
int c[100];
int n_prepare;
long long l[100];//do dai cua fibword
long long mc[100];
void preprocessing (){
    fibword[1] = '1';
    fibword[0] = '0';
    l[0] = 1,l[1] = 1;
    n_prepare = 2;
    for(int i = 2,l0=1,l1=1;l0<=100;i++){
        fibword[i] = fibword[i-1] + fibword[i-2];
        l[i] = l[i-1] + l[i-2];
        l0 = l1;
        l1 = l[i];
        n_prepare++;
    }

}
// long long count(string s,string p){//dem so lan p xuat hien trong s theo thuat toan vet can
//     plen = p.length();
//     slen = s.length();
//     long long res = 0;
//     for(int i = 0;i<slen;i++){
//         if(p == s.substr(i,plen)){
//             res++;
//         }
//     }
//     return res;

// }
long long count(string s,string p){
    int ls = s.size();
    int lp = p.size();
    long long res = 0;
    for(int i = 0;i <= ls-lp;i++){
        res++;
        for(int j = 0;j<lp;j++){
            if(p[j] != s[i+j]){
                res--;
                break;
            }
        }
    }
    return res;
}
long long count(int n,string p){//dem so lan p xuat hein trong f(n)
    if(c[n] < 0){
        c[n] = count(n-1,p) + count(n-2,p) + mc[n%2];
    }
    return c[n];
}
long long solve(int n,string p){
    int lp = p.size();
    if(n<n_prepare && l[n] < lp){
        return 0;
    }
    for(int j = 0;j<=n;j++){
        c[j] = -1;
    }
    int i = 1;
    while(l[i-1] <lp){
        i++;
    }
    c[i-1] = count(f[i-1],p);
    c[i] = count(f[i],p);
    string x = f[i].substr(0,lp-1);
    string a = f[i-1].substr(l[i-1] - (lp-1));
    string b = f[i].substr(l[i] - (lp-1));
    mc[i%2] = count(a+x,p);
    mc[(i+1)%2] = count(b+x,p);
    return count(n,p);
}
void input(){
    preprocessing();
    for(int i = 1;scanf("%d",&n) != EOF;i++){
        cin>>n;
        cin >> p;
        cout<<"Case: "<<i;
    }
}