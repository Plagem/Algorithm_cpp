#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll a, b, c;
ll sol = 1;
ll dp[32];

int main()
{
    cin >> a >> b >> c;

    dp[0] = a%c;
    for(int i = 1; i < 32; i++)
    {
        dp[i] = (dp[i-1] * dp[i-1]) % c;
    }

    for(int i = 0; i < 32; i++)
    {
        if(b % 2 == 1)
        {
            sol *= dp[i];
            sol %= c;
        }
        b /= 2;
    }

    cout << sol;
}