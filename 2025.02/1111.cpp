#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;

int dp[500][500];
int map[500][500];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y)
{
    if(x == N-1 && y == M-1) return 1;

    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i]; int ny = y + dy[i];
        if(0 <= nx && nx < N && 0 <= ny && ny < M)
        {
            if(map[x][y] > map[nx][ny])
            {
                dp[x][y] += dfs(nx, ny);
            }
        }
    }

    return dp[x][y];
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    dfs(0,0);
    cout << dp[0][0] << endl;
}