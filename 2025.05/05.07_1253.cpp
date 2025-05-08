#include <iostream>
#include <vector>
#include <algorithm>
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

    int sol = 0;
    for(int i = 0; i < n; i++)
    {
        int start = 0;
        int end = n-1;
        
        if(i == 0) start++;
        if(i == n-1) end--;

        while(start < end)
        {
            int cur = v[start] + v[end];
            if(cur > v[i])
            {
                end--;
                if(i == end) end--;
            }
            else if(cur == v[i])
            {
                sol++;
                break;
            }
            else
            {
                start++;
                if(i == start) start++;
            }
        }
    }

    cout << sol;
}