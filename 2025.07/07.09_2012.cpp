#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> v;

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    long long sol = 0;

    for(int i = 0; i < n; i++)
    {
        sol += abs((i+1) - v[i]);
    }

    cout << sol;
}