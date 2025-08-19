#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int>> lightSwitch[101][101];
queue<pair<int, int>> switchQueue;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool bessiVisited[101][101]; // 베시가 실제로 이동한 위치
bool lightMap[101][101]; // 불이 켜져있는 방의 위치

void bfs()
{
    bool visited[101][101] = {};
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        
        if(!bessiVisited[cur.first][cur.second])
        {
            bessiVisited[cur.first][cur.second] = true;
            for(int i = 0; i < lightSwitch[cur.first][cur.second].size(); i++)
            {
                switchQueue.push(lightSwitch[cur.first][cur.second][i]);
            }
        }

        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(0 < nx && nx <= n && 0 < ny && ny <= n)
            {
                if(!visited[nx][ny] && lightMap[nx][ny])
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int printMap()
{
    int sol = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int p = lightMap[i][j] ? 1 : 0;
            sol += p;
        }
    }
    return sol;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int t1, t2, t3, t4;
        cin >> t1 >> t2 >> t3 >> t4;
        lightSwitch[t1][t2].push_back({t3, t4});
    }

    lightMap[1][1] = true;
    bfs();

    while(!switchQueue.empty())
    {
        pair<int, int> cur = switchQueue.front();
        switchQueue.pop();
        if(!lightMap[cur.first][cur.second])
        {
            lightMap[cur.first][cur.second] = true;
            bfs();
        }
    }

    cout << printMap();
}