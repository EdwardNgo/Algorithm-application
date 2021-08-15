#include <iostream>
#include <map>

using namespace std;

template <class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    map<int, double> c;
    // c = a;
    auto i = a.begin();
    auto j = b.begin();
    auto last1 = a.end();
    auto last2 = b.end();
    while (i != last1 && j != last2)
    {
        c.insert(pair<int, double>(i->first, 0));
        c.insert(pair<int, double>(j->first, 0));
        i++;
        j++;
    }
    // while (i != last1 && j != last2){
    // }
    auto k = c.begin();
    auto last3 = c.end();
    while (k != last3)
    {
        double value1, value2;
        auto key1 = a.find(k->first);
        auto key2 = b.find(k->first);

        value1 = key1->second;
        value2 = key2->second;
        cout << value1 << " " << value2;
        if (value1 < value2)
        {
            c.at(k->first) = value2;
        }
        else
        {
            c.at(k->first) = value1;
        }
        k++;
    }
    return c;
}

template <class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    map<int, double> c;

    auto i = a.begin();
    auto j = b.begin();
    auto last1 = a.end();
    auto last2 = b.end();
    while (i != last1 && j != last2)
    {

        if (i->first == j->first)
        {
            if (i->second < j->second)
            {
                c.insert(pair<int, double>(i->first, i->second));
            }
            else
            {
                c.insert(pair<int, double>(i->first, j->second));
            }

            i++;
            j++;
        }
        else if (i->first < j->first)
        {
            i++;
        }
        else if (i->first > j->first)
        {
            // c.insert(pair<int, double>(j->first, j->second));
            j++;
        }
    }

    return c;
}

template <class T>
void print_fuzzy_set(const std::map<T, double> &a)
{
    cout << "{ ";
    for (const auto &x : a)
    {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main()
{
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = ";
    print_fuzzy_set(a);
    std::cout << "B = ";
    print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: ";
    print_fuzzy_set(c);
    std::cout << "Intersection: ";
    print_fuzzy_set(d);
}