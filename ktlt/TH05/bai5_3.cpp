#include <iostream>
using namespace std;
#include <string.h>
#include <stack>

int par(string str)
{
    int a = str.length();
    stack<char> st;
    // char x, y;
        for(char c : str){
        if(c == '('|| c == '{' || c == '['){
            st.push(c);
        }else{
            if(st.empty()) return false;
            if(c == ')' && st.top() != '(') return false;
            if(c == '}' && st.top() != '{') return false;
            if(c == ']' && st.top() != '[') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    int n;
    string str;
    cin >> n;

    for (int i = 0; i < n; i++)
    {

        cin >> str;
        cout << par(str) << endl;
    }
}