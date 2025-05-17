#include <iostream>
#include <queue>
using namespace std;

int n, m;
int sol;

int arr[101][101];
bool visited[101][101];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(int x, int y)
{
    int num = arr[x][y];

    queue<pair<int, int>> inq;

    queue<pair<int, int>> q;
    inq.push(make_pair(x, y));
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny])
            {
                if(arr[nx][ny] == num)
                {
                    q.push(make_pair(nx, ny));
                    inq.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }

    bool flag = true;
    while(!inq.empty())
    {
        pair<int, int> cur = inq.front();
        inq.pop();

        for(int i = 0; i < 8; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if(arr[nx][ny] > num)
                {
                    flag = false;
                }
            }
        }
    }

    if(flag)
    {
        sol++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j])
            {
                bfs(i, j);
            }
        }
    }

    cout << sol;
}