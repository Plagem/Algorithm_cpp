#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int n;
int inputArr[100][100];
int newArr[100][100];
int solArr[100][100];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void makeArr()
{
    int islandNum = 1;
    bool visited[100][100] = {};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(visited[i][j] || inputArr[i][j] == 0) continue;

            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            while(!q.empty())
            {
                pair<int, int> cur = q.front(); q.pop();
                newArr[cur.first][cur.second] = islandNum;
                for(int k = 0; k < 4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if(0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny])
                    {
                        if(inputArr[nx][ny] == 1)
                        {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
            islandNum++;
        }
    }
}

int bfs(int islandNum, int x, int y)
{
    bool visited[100][100] = {};
    queue<tuple<int, int, int>> q;
    q.push({x, y, 0});
    visited[x][y] = true;
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        if(newArr[get<0>(cur)][get<1>(cur)] != islandNum && newArr[get<0>(cur)][get<1>(cur)] != 0)
        {
            return get<2>(cur);
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny])
            {
                if(newArr[nx][ny] != islandNum)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, get<2>(cur)+1});
                }
            }
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> inputArr[i][j];
        }
    }

    makeArr();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(newArr[i][j] == 0) continue;
            solArr[i][j] = bfs(newArr[i][j], i, j);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(newArr[i][j] == 0) continue;
            solArr[i][j] = bfs(newArr[i][j], i, j);
        }
    }

    int sol = 1e9;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(solArr[i][j] != 0)
            {
                sol = min(sol, solArr[i][j]-1);
            }
        }
    }

    cout << sol;
}