#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n;
long long sol;
map<int, vector<int>> m;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        m[t2].push_back(t1);
    }

    for(auto it = m.begin(); it != m.end(); it++)
    {
        vector<int>& v = it->second;
        sort(v.begin(), v.end());
        if(v.size() == 1) continue;
        for(int i = 0; i < v.size(); i++)
        {
            int so = 1e9;
            vector<int> tv;
            if(i-1 >= 0) tv.push_back(v[i-1]);
            if(i+1 < v.size()) tv.push_back(v[i+1]);

            for(int j = 0; j < tv.size(); j++)
            {
                so = min(so, abs(v[i] - tv[j]));
            }
            sol += so;
        }
    }

    cout << sol;
}