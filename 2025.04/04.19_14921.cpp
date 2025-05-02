#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int sol = 1e9;

int main()
{
    vector<int> liquids;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        liquids.push_back(t);
    }

    sort(liquids.begin(), liquids.end(), [](int a, int b){return abs(a) < abs(b);});

    for(int i = 0; i < n-1; i++)
    {
        if(abs(sol) > abs(liquids[i] + liquids[i+1]))
        {
            sol = liquids[i] + liquids[i+1];
        }
    }

    cout << sol;
}