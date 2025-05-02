#include <iostream>

int appleMap[301][301];
int dp[301][301][301];

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, sol = -1e9;
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            cin >> appleMap[i][j];
            dp[i][j][1] = appleMap[i][j];
            sol = max(appleMap[i][j], sol);
        }

    for(int size = 2; size <= N; size++)
    {
        for(int x = 0; x <= N-size; x++)
            for(int y = 0; y <= N-size; y++)
            {
                if(size%2 == 0) // size 짝수일 때
                {
                    dp[x][y][size] = dp[x][y][size/2] + dp[x+size/2][y][size/2]
                    + dp[x][y+size/2][size/2] + dp[x+size/2][y+size/2][size/2];
                }
                else
                {
                    dp[x][y][size] = dp[x][y][size/2+1] + dp[x+size/2+1][y][size/2]
                    + dp[x][y+size/2+1][size/2] + dp[x+size/2][y+size/2][size/2+1]
                    - dp[x+size/2][y+size/2][1];
                }
                sol = max(dp[x][y][size], sol);
            }
    }

    cout << sol;
}