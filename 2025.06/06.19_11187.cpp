#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, d, n;
int sol = 0;
vector<int> birds;

int main()
{
    cin >> l >> d >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        birds.push_back(t);
    }

    sort(birds.begin(), birds.end());

    int prev = 6-d;
    int end = l-(6-d);
    for(int i = 0; i <= n; i++)
    {
        int cur = 0;
        if(i == n)
        {
            cur = end;
        }
        else
        {
            cur = birds[i];
        }
        sol += (cur - prev) / d - 1;
        prev = cur;
    }

    cout << sol;
}