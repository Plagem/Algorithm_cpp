#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> abstime;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        abstime.push_back(t1 - t2);
    }

    if(n%2 == 1) cout << 1;
    else
    {
        sort(abstime.begin(), abstime.end());
        cout << abs(abstime[n/2]-abstime[n/2-1]) + 1;
    }
}