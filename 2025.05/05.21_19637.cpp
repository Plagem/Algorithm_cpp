#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector<pair<string, int>> v;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >>m;
    for(int i = 0; i < n; i++)
    {
        string s; int t;
        cin >> s >> t;
        v.push_back(make_pair(s, t));
    }


    for(int i = 0; i < m; i++)
    {
        int t;
        cin >> t;

        int start = 0; int end = n-1;
        int mid = (start + end) / 2;
        while(start <= end)
        {
            mid = (start + end) / 2;
            if(t <= v[mid].second)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        if(t > v[mid].second)
        {
            cout << v[mid+1].first << '\n';
        }
        else
        {
            cout << v[mid].first << '\n';
        }
    }
}