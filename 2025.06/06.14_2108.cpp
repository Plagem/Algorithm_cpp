#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int arr[500000];
map<int, int> m;

bool vsort(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second != b.second ? a.second > b.second : a.first < b.first;
}

int main()
{
    cin >> n;
    int all = 0;
    int maxidx = 0;
    int maxnum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[arr[i]]++;
        if(m[arr[i]] > maxnum)
        {
            maxnum = m[arr[i]];
            maxidx = arr[i];
        }
        all += arr[i];
    }

    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), vsort);

    int f = v[0].first;
    if(v.size() > 1 && v[0].second == v[1].second)
    {
        f = v[1].first;
    }

    sort(arr, arr+n);

    cout << round((double)all / n) + 0.0 << endl;
    cout << arr[n/2] << endl;
    cout << f << endl;
    cout << arr[n-1] - arr[0] << endl;
}