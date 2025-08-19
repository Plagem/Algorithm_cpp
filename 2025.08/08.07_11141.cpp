#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> ps;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ps.push_back(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        ps.push_back(ps[i-1] + t);
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        cout << ps[t2] - ps[t1-1] << "\n";
    }
}