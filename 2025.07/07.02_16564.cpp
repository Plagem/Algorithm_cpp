#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long n, m;
vector<long long> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        long long t1;
        cin >> t1;
        v.push_back(t1);
    }
    sort(v.begin(), v.end());

    long long start = v[0];
    long long end = v[0] + m;

    long long sol = 0;
    while(start <= end)
    {
        long long mid = (start + end) / 2;
        long long acc = 0;
        for(int level : v)
        {
            if(level < mid)
            {
                acc += mid - level;
            }
        }

        if(acc <= m)
        {
            start = mid + 1;
            sol = max(mid, sol);
        }
        else
        {
            end = mid - 1;   
        }
    }

    cout << sol;
}