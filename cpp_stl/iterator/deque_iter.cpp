#include <iostream>
#include <deque>
using namespace std;

int main ()
{
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);
    dq.push_back(50);

    deque<int>::iterator deiter;
    deiter = dq.begin();
    cout << deiter[0] << endl;
    cout << deiter[1] << endl;
    cout << deiter[2] << endl;
    cout << deiter[3] << endl;
    cout << deiter[4] << endl << endl;

    deiter += 2;
    cout << *deiter << endl;

    return 0;
}