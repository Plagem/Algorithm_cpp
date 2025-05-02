#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
int arr[100][100];
int rec[100][100];
bool visited[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = s[j] - '0';
            rec[i][j] = 1e9;
            visited[i][j] = false;
        }
    }

    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    visited[0][0] = true;
    rec[0][0] = 1;
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if(arr[nx][ny] == 0 || visited[nx][ny]) continue;
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                rec[nx][ny] = min(rec[nx][ny], rec[cur.first][cur.second] + 1);
            }
        }
    }

    cout << rec[n-1][m-1];
}