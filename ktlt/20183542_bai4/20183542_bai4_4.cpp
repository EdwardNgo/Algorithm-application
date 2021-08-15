#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool IsEven(int i) { return ((i % 2) == 0); }
void print_vector(const vector<int> &a)
{
    for (int v : a)
        cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    // remove_if(a.begin(), a.end(), IsEven);
    for (auto i = a.begin(); i != a.end(); ++i) {
        if (*i % 2 == 0) {
            a.erase(i);
            i--;
        }
    }
}

void sort_decrease(vector<int> &a)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    sort(a.begin(), a.end(), greater<>());
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    int total_size = a.size() + b.size();
    vector<int> c(total_size );
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    sort(c.begin(), c.end(), greater<>());
    return c;
}

int main()
{
    int m, n, u;
    std::vector<int> a, b;

    std::cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        std::cin >> u;
        a.push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}