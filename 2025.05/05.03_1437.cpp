#include <iostream>
#include <vector>
using namespace std;

int n;
int sol = 1;
vector<int> bunhe;

int main()
{
    int num2, num3;
    cin >> n;
    if(n%3 == 1) num2 = 2;
    else if(n%3 == 2) num2 = 1;
    else num2 = 0;
    num3 = (n-2*num2)/3;

    if(n < 2)
    {
        cout << n;
    }
    else
    {
        for(int i = 0; i < num2; i++)
        {
            sol *= 2;
            sol %= 10007;
        }
        for(int i = 0; i < num3; i++)
        {
            sol *= 3;
            sol %= 10007;
        }

        cout << sol;
    }
}