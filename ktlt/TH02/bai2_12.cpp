#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct
{
    int key;
    int value;
} Dict;

int main()
{
    Dict a[100];

    Dict input;
    vector<Dict> V;
    int temp1, temp2;
    int i = 0;
    while (cin >> temp1 >> temp2 ){
        a[i].key = temp1;
        a[i].value = temp2;
        V.push_back(a[i]);
        i++;
    }
    sort(V.begin(), V.end(), [](Dict x, Dict y) {
        if (x.value == y.value)
            return x.key > y.key;
        else
            return x.value > y.value;
    });

    for (const auto i : V)
        cout << i.key << " " << i.value << endl;
}
