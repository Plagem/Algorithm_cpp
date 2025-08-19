#include <iostream>
using namespace std;

int n;

void logic(int a)
{
    int m = 0;
    for(int i = 1; i <= a; i++)
    {
        m = (m * 10 + 1) % a;
        if(m == 0)
        {
            cout << i << endl;
            return;
        }
    }    
}

int main()
{
    while(cin >> n)
    {
        logic(n);
    }
}