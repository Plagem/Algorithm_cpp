#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;
    int sol = 10;
    for(int i = 1; i*2 <= n; i*=2)
    {
        sol++;
    }

    cout << sol;
}