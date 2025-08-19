#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;

vector<int> solv;

int main()
{
    cin >> n;
    int s, e;
    cin >> s >> e;

    for(int i = 1; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        v.push_back({s, e});
    }

    int sol = 1e9;
    for(int i = s; i <= e; i++)
    {
        vector<int> tempv;
        tempv.push_back(i);

        int acc = 0;
        int cur = i;
        for(int j = 0; j < v.size(); j++)
        {
            pair<int, int> bumi = v[j];
            if(bumi.first <= cur && cur <= bumi.second)
            {
                tempv.push_back(cur);
            }
            else if(cur < bumi.first)
            {
                acc += bumi.first - cur;
                cur = bumi.first;
                tempv.push_back(cur);
            }
            else if(bumi.second < cur)
            {
                acc += cur - bumi.second;
                cur = bumi.second;
                tempv.push_back(cur);
            }
        }

        if(sol > acc)
        {
            solv = tempv;
            sol = acc;
        }
    }

    cout << sol << '\n';
    for(int i = 0; i < solv.size(); i++)
    {
        cout << solv[i] << '\n';
    }
}