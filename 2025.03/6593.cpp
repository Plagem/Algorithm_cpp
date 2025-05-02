// 6593 : 상범빌딩
// 3D BFS

#include <iostream>
#include <tuple>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

char building[30][30][30];
bool visited[30][30][30];

int Logic()
{
    memset(building, 0, sizeof(building));
    memset(visited, 0, sizeof(visited));
    // Input
    int curPos[3];
    int sol = -1;

    int l, r, c;
    cin >> l >> r >> c;
    if(l == 0 && r == 0 && c == 0)
    {
        return -1;
    }

    int t;
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < r; j++)
        {
            string str;
            cin >> str;
            for(int k = 0; k < c; k++)
            {
                building[i][j][k] = str[k];
                if(str[k] == 'S')
                {
                    curPos[0] = i; curPos[1] = j; curPos[2] = k;
                }
            }
        }
        cin.ignore();
    }

    // Logic
    queue<pair<tuple<int, int, int>, int>> q;
    visited[curPos[0]][curPos[1]][curPos[2]] = true;
    q.push(make_pair(make_tuple(curPos[0],curPos[1],curPos[2]), 0));
    while(!q.empty())
    {
        pair<tuple<int, int, int>, int> cur = q.front(); q.pop();
        curPos[0] = get<0>(cur.first); curPos[1] = get<1>(cur.first); curPos[2] = get<2>(cur.first);

        for(int i = 0; i < 6; i++)
        {
            int nx = curPos[0] + dx[i]; int ny = curPos[1] + dy[i]; int nz = curPos[2] + dz[i];
            if(0 <= nx && nx < l && 0 <= ny && ny < r && 0 <= nz && nz < c)
            {
                if(building[nx][ny][nz] != '#' && !visited[nx][ny][nz])
                {
                    visited[nx][ny][nz] = true;
                    if(building[nx][ny][nz] == 'E')
                    {
                        sol = cur.second+1;
                    }
                    tuple<int, int, int> nextPos = make_tuple(nx, ny, nz);
                    q.push(make_pair(nextPos, cur.second+1));
                }
            }
        }
    }

    if(sol == -1)
    {
        cout << "Trapped!" << endl;;
    }
    else
    {
        cout << "Escaped in " << sol << " minute(s)." << endl;
    }

    return 0;
}

int main()
{
    while(true)
    {
        int n = Logic();
        if(n == -1) break;
    }
}