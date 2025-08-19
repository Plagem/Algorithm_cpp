#include <iostream>
typedef long long ll;
using namespace std;

ll n;

int main()
{
    cin >> n;

    ll start = 1;
    ll end = 2 * 1e9;

    while(start < end)
    {
        ll mid = start + (end - start) / 2;
        ll Sn = 3 * (mid * mid) - 3 * mid + 1;

        if(Sn < n)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    cout << end;
}