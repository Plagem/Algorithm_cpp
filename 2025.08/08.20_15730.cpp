#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m;
int inputArr[100][100];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int height)
{
    int sliceArr[102][102] = {};
    bool visited[102][102] = {};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(inputArr[i][j] >= height)
            {
                sliceArr[i+1][j+1] = 1;
            }
        }
    }

    // 테두리 걸러내기 한 번
    queue<pair<int, int>> q;
    q.push({0,0});
    visited[0][0] = true;
    while(!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(0 <= nx && nx < n+2 && 0 <= ny && ny < m+2 && !visited[nx][ny])
            {
                if(sliceArr[nx][ny] == 0)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    int r = 0;
    for(int i = 0; i < n+2; i++)
    {
        for(int j = 0; j < m+2; j++)
        {
            if(!visited[i][j] && sliceArr[i][j] == 0)
            {
                r++;
            }
        }
    }

    return r;
}

int main()
{
    cin >> n >> m;
    int maxHeight = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int t; cin >> t;
            inputArr[i][j] = t;
            maxHeight = max(maxHeight, t);
        }
    }

    int sol = 0;
    for(int h = 1; h <= maxHeight; h++)
    {
        sol += bfs(h);
    }

    cout << sol;
}