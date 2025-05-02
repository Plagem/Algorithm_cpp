#include <iostream>
using namespace std;

int divide(int a, int b)
{
    if(a%b == 0) return b;
    else return divide(b, a%b);
}

int main()
{
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    int aa, bb;
    bb = b1 * b2;
    aa = b1 * a2 + b2 * a1;
    int d = divide(max(aa, bb), min(aa, bb));
    cout << aa / d << " " << bb / d;
}