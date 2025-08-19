#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m;
int sliceArr[10][52][52];
int inputArr[50][50];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int height)
{
    //0 ~ n-1까지

    bool visited[52][52] = {};
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
                if(sliceArr[height][nx][ny] == 0)
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
            if(!visited[i][j] && sliceArr[height][i][j] == 0)
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
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            inputArr[i][j] = s[j] - '0';
        }
    }

    for(int h = 1; h <= 9; h++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(inputArr[i][j] >= h)
                {
                    sliceArr[h][i+1][j+1] = 1;
                }
            }
        }
    }

    int sol = 0;
    for(int h = 1; h <= 9; h++)
    {
        sol += bfs(h);
    }

    cout << sol;
}