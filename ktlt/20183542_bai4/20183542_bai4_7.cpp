#include <iostream>
#include <set>
#include <algorithm> // std::set_intersection, std::sort

using namespace std;

template <class T>
set<T> set_union(const set<T> &a, const set<T> &b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    set<int> c;
    for (auto i = a.begin(); i != a.end(); ++i)
    {
        c.insert(*i);
    }
    for (auto i = b.begin(); i != b.end(); ++i)
    {
        c.insert(*i);
    }
    return c;
}

template <class T>
set<T> set_intersection(const set<T> &a, const set<T> &b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    set<int> result;

    // set_intersection(a.begin(), a.end(),
    //                  b.begin(), b.end(),
    //                  v_intersection.begin());
    // // v_intersection.resize(it - v_intersection.begin());
    // return v_intersection;
    auto i = a.begin();
    auto j = b.begin();
    auto last1 = a.end();
    auto last2 = b.end();
    while (i != last1 && j != last2)
    {
        if (*i < *j)
            ++i;
        else if (*j < *i)
            ++j;
        else
        {
            result.insert(*i);
            // ++result;
            ++i;
            ++j;
        }
    }
    return result;
}

template <class T>
void print_set(const std::set<T> &a)
{
    for (const T &x : a)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::set<int> a = {1, 2, 3, 5, 7};
    std::set<int> b = {2, 4, 5, 6, 9};
    std::set<int> c = set_union(a, b);
    std::set<int> d = set_intersection(a, b);

    std::cout << "Union: ";
    print_set(c);
    std::cout << "Intersection: ";
    print_set(d);

    return 0;
}