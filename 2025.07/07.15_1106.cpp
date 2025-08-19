#include <iostream>
#include <vector>
using namespace std;

int c, n;
vector<pair<int, int>> v;
int dp[2001];

int main()
{
    cin >> c >> n;
    for(int i = 0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v.push_back({t1, t2});
    }

    for(int i = 0; i <= c; i++)
    {
        for(int j = 0; j < v.size(); j++)
        {
            pair<int, int> cur = v[j];
            // 소모하는 돈 // 사람 수
            bool b = false;
            if(dp[i+cur.second] == 0)
            {
                dp[i+cur.second] = dp[i]+cur.first;
                b = true;
            } 
            else
            {
                if(dp[i+cur.second] > dp[i]+cur.first)
                {
                   dp[i+cur.second] = dp[i]+cur.first;
                   b = true;
                }
            }

            if(b)
            {
                for(int k = i+cur.second-1; k > 0; k--)
                {
                    if(dp[k] == 0 || dp[k] > dp[i+cur.second])
                    {
                        dp[k] = dp[i+cur.second];  
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    
    int sol = 1e9;
    for(int i = c; i <= c+100; i++)
    {
        if(dp[i] != 0)
        {
            sol = min(sol, dp[i]);
        }
    }
    cout << sol;
}