#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    v.push_back(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(v[i] + t);
    }

    for(int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        cout << v[t2] - v[t1-1] << "\n";
    }
}