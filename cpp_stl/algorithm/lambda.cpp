#include <iostream>
using namespace std;

int main()
{
    int x = 10;

    auto l1 = [&]()
    {
        x = 5;
        return x;
    };

    auto l2 = [&, x = x+100]()
    {
        return x;
    };

    cout << l1() << endl;
    cout << x << endl;
    cout << l2() << endl;
    cout << x << endl;
}