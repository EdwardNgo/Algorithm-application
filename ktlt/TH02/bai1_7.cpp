#include <iostream>
using namespace std;
//Viết hàm tính tổng các phần tử trong hai mảng.
//Yêu cầu sử dụng function template để cho phép hàm làm việc với các mảng số nguyên lẫn số thực.
//# viết hàm arr_sum
/*****************
# YOUR CODE HERE #
*****************/
template <typename T>
T arr_sum(T arr1[], int n , T arr2[], int m )
{
    T res = 0;
    int i, j;
    for (i = 0; i < n; i++)
    {
        res += arr1[i];
    }
    for (j = 0; j < m; j++)
    {
        res += arr2[j];
    }
    return res;
}
int main()
{
    int val;
    cin >> val;

    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}
