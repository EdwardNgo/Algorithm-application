#include <iostream>
using namespace std;
void printChild(int *arr, int l, int r)
{
    for (int k = l; k <= r; k++)
    {
        cout << *(arr + k) << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout<< "Ho Va Ten: Ngo Song Viet Hoang"<<endl;
    cout<< "MSSV: 20183542" <<endl;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> *(arr + i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            printChild(arr, i, j);
        }
    }
    delete[] arr;
    return 0;
}
