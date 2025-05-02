#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> punks;

int main()
{
    int n, l;
    cin >> n >> l;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        punks.push_back(t);
    }

    sort(punks.begin(), punks.end());

    int sol = 0; int start = punks[0];

    for(int i = 1; i < n; i++)
    {
        if(l <= punks[i] - start)
        {
            sol++;
            start = punks[i];
        }
    }

    cout << sol + 1;
}