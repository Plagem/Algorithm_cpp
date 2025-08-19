#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v.push_back({t1, t2});
    }

    int sol = 0;
    for(int i = 1; i < n; i++)
    {
        pair<int, int> prev = v[i-1];
        pair<int, int> cur = v[i];
        sol += abs(prev.first - cur.first) + abs(prev.second - cur.second);
    }

    int m = 0;
    for(int i = 2; i < n; i++)
    {
        pair<int, int> pprev = v[i-2];
        pair<int, int> prev = v[i-1];
        pair<int, int> cur = v[i];

        int ppp = abs(pprev.first - prev.first) + abs(pprev.second - prev.second);
        int pc = abs(prev.first - cur.first) + abs(prev.second - cur.second);
        int ppc = abs(pprev.first - cur.first) + abs(pprev.second - cur.second);
        m = max(m, ppp + pc - ppc);
    }
    
    cout << sol - m;
}