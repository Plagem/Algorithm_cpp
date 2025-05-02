#include <iostream>
#include <string>
#include <vector>
#include <queue>

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M;
int x1, Y1, x2, y2;
char map[301][301];

using namespace std;

bool do_jump()
{
    vector<vector<bool>> visited(N+1, vector<bool>(M+1, false));

    queue<pair<int, int>> q;
    pair<int, int> startpos = make_pair(x1, Y1);
    q.push(startpos);
    visited[x1][Y1] = true;

    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int cx, cy;
        cx = cur.first; cy = cur.second;

        if(map[cx][cy] == '1')
        {
            map[cx][cy] = 'x';
            continue;
        }
        if (map[cx][cy] == '#')
        {
            return true;
        }

        for(int i = 0; i < 4; i++)
        {
            int nx, ny;
            nx = cx + dx[i]; ny = cy + dy[i];

            if(1 > nx || nx > N || 1 > ny || ny > M) continue;
            if(visited[nx][ny] == true || map[nx][ny] == 'x') continue;
            
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(map[i][j] == 'x')
            {
                map[i][j] = '0';
            }
        }
    }

    return false;
}

int main()
{
    // 입력
    cin >> N >> M;
    cin >> x1 >> Y1 >> x2 >> y2;
    for(int i = 1; i <= N; i++)
    {
        string temps;
        cin >> temps;
        for(int j = 1; j <= M; j++)
        {
            map[i][j] = temps[j-1];
        }
    }

    int kungkwang = 0;
    while(true)
    {
        kungkwang++;
        if(do_jump() == true)
        {
            break;
        }
    }
    cout << kungkwang;
}