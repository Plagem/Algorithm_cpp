#include <iostream>
using namespace std;

long long n;
long long sol;

void input()
{
    cin >> n;
}

void logic()
{
    for(int i = 1; i <= n; i++)
    {
        sol += (n / i) * i;
    }
}

void output()
{
    cout << sol;
}

int main()
{
    input();
    logic();
    output();
}