#include <vector>
#include <iostream>
using namespace std;

int n;
int st = 0;
int fidx = 0, sidx = 0;
int maxs = 1;
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

    for(int i = 1; i < v.size(); i++)
    {
        if(v[i] != v[i-1])
        {
            if(v[i] != v[fidx] && v[i] != v[sidx])
            {
                st = sidx;
            }
            fidx = sidx;
            sidx = i;
        }
        maxs = max(maxs, i - st + 1);

        // cout << st << fidx << sidx << endl;
    }

    cout << maxs;
}