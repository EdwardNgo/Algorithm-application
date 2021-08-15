#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip>
//tinh tong hieu tich thuong cua so phuc
using namespace std;

struct Complex
{
    double real;
    double imag;
};

Complex operator+(Complex a, Complex b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    Complex res;
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;
    return res;
}

Complex operator-(Complex a, Complex b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    Complex res;
    res.real = a.real - b.real;
    res.imag = a.imag - b.imag;
    return res;
}

Complex operator*(Complex a, Complex b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    Complex res;
    res.real = a.real * b.real - a.imag * b.imag;
    res.imag = a.real * b.imag + a.imag * b.real;
    return res;
}

Complex operator/(Complex a, Complex b)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    Complex res;
    res.real = (a.real * b.real + a.imag * b.imag) / (pow(b.real, 2) + pow(b.imag, 2));
    res.imag = (b.real * a.imag - a.real*b.imag) / (pow(b.real, 2) + pow(b.imag, 2));
    return res;
}

ostream &operator<<(ostream &out, const Complex &a)
{
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main()
{
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;

    Complex a{real_a, img_a};
    Complex b{real_b, img_b};

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    return 0;
}