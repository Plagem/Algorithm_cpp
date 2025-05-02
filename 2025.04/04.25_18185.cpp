#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n;
ll maxHeight;
ll sol;
vector<ll> arr;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        maxHeight = max(maxHeight, t);
        arr.push_back(t);
    }

    for(int curHeight = 1; curHeight <= maxHeight; curHeight++)
    {
        ll length = 0;
        for(int i = 0; i <= n; i++)
        {
            if(i == n)
            {
                sol += ((length+2)/3)*3 + (length-((length+2)/3))*2;
                continue;
            }
            if(arr[i] >= curHeight)
            {
                length++;
            }
            else
            {
                ll budget = ((length+2)/3)*3 + (length-((length+2)/3))*2;
                sol += budget;
                length = 0;
            }
            
        }
    }

    cout << sol;
}