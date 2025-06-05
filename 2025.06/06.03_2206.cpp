#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[1000][1000];
int visited[1000][1000][2];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<pair<int, int>, int>> q;

int main()
{
    // Input
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = s[j] - '0';
        }
    }

    // Logic
    q.push({{0, 0}, 0});
    visited[0][0][0] = 1;
    while(!q.empty())
    {
        pair<pair<int, int>, int> cur = q.front(); q.pop();
        int x = cur.first.first; int y = cur.first.second;
        int b = cur.second;

        if(x == n-1 && y == m-1)
        {
            cout << visited[x][y][b];
            return 0;
        }

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i]; int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && visited[nx][ny][b] == 0)
            {
                if(arr[nx][ny] == 1 && b == 0 && visited[nx][ny][1] == 0)
                {
                    visited[nx][ny][1] = visited[x][y][b] + 1;
                    q.push({{nx, ny}, 1});
                }
                else if(arr[nx][ny] == 0)
                {
                    visited[nx][ny][b] = visited[x][y][b] + 1;
                    q.push({{nx, ny}, b});
                }
            }
        }
    }

    cout << "-1";
}