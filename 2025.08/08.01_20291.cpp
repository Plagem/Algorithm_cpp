#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
map<string, int> m;
vector<pair<string, int>> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        bool go = false;
        string ss;
        for(int j = 0; j < s.size(); j++)
        {    
            if(go)
            {
                ss += s[j];
            }
            if(s[j] == '.') go = true;
        }

        m[ss]++;
    }

    for(auto it = m.begin(); it != m.end(); it++)
    {
        v.push_back({it->first, it->second});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}