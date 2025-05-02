#include <iostream>
#include <vector>
using namespace std;

int n, m;
int d;
vector<vector<int>> arr;
vector<vector<int>> dp;

void Logic(int x, int y)
{
    for(int dx = 1; dx <= d; dx++)
    {
        int nx = x + dx;
        if(nx >= n) continue;
        for(int dy = -(d - dx); dy <= d-dx; dy++)
        {
            int ny = y + dy;
            if(0 <= ny && ny < m)
            {
                dp[x][y] = max(dp[x][y], arr[x][y]*arr[nx][ny] + dp[nx][ny]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int sol = -2e9;
    cin >> n >> m >> d;
    for(int i = 0; i < n; i++)
    {
        arr.push_back(vector<int>());
        dp.push_back(vector<int>());
        for(int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            arr[i].push_back(t);
            dp[i].push_back(-2e9);
        }
    }

    for(int i = 0; i < m; i++)
    {
        dp[n-1][i] = 0;
    }

    for(int i = n-2; i >= 0; i--)
    {
        for(int j = 0; j < m; j++)
        {
            Logic(i, j);
        }
    }

    for(int i = 0; i < m; i++)
    {
        sol = max(sol, dp[0][i]);
    }

    cout << sol;
}