#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
#include <math.h> /* sqrt */
using namespace std;
using Point = pair<double, double>;

double area(Point a, Point b, Point c)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    double egde1, egde2, egde3, c_all, half_c;
    egde1 = sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
    egde2 = sqrt(pow(b.first - c.first, 2) + pow(b.second - c.second, 2));
    egde3 = sqrt(pow(a.first - c.first, 2) + pow(a.second - c.second, 2));
    c_all = egde1 + egde2 + egde3;
    half_c = c_all / 2;
    return sqrt(half_c * (half_c - egde1) * (half_c - egde2) * (half_c - egde3));
}

int main()
{
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    return 0;
}