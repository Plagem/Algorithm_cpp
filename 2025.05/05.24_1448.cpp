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

    bool flag = false;
    for(int i = n-1; i >= 2; i--)
    {
        if(v[i] < v[i-1] + v[i-2])
        {
            flag = true;
            cout << v[i] + v[i-1] + v[i-2];
            break;
        }
    }
    if(!flag)
    {
        cout << "-1";
    }
}