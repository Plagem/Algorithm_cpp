#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int n;
string boj;

int dp[1000][3] = {0,};
map<char, int> m;

int main()
{
    m.insert({'B', 0});
    m.insert({'O', 1});
    m.insert({'J', 2});

    fill(dp[0], dp[1000], -1);

    cin >> n >> boj;
    dp[0][0] = 0;
    
    for(int i = 1; i < 1000; i++)
    {
        int curidx = m[boj[i]];
        for(int k = 0; k < i; k++)
        {
            if(dp[k][(curidx+2)%3] != -1)
            {
                if(dp[i][curidx] == -1)
                {
                    dp[i][curidx] = dp[k][(curidx+2)%3] + (i-k)*(i-k);
                }    
                else
                {
                    dp[i][curidx] = min(dp[i][curidx], dp[k][(curidx+2)%3] + (i-k)*(i-k));
                }
            }
        }
    }

    cout << dp[n-1][m[boj[n-1]]];
}