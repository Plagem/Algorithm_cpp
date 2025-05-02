#include <iostream>
#include <queue>

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int visited[500][500] = {0, };
int mal[1000][2];

struct bfsq
{
    int x;
    int y;
    int time;
};

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    for(int i = 0; i < M; i++)
    {
        cin >> mal[i][0] >> mal[i][1];
    }

    queue<bfsq> q;
    bfsq knight = {X-1, Y-1, 1};
    q.push(knight);

    while(!q.empty())
    {
        int cur[3] = {q.front().x, q.front().y, q.front().time};
        q.pop();

        for(int i = 0; i < 8; i++)
        {
            int nx = cur[0] + dx[i];
            int ny = cur[1] + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] != 0) continue;

            visited[nx][ny] = cur[2]+1;
            bfsq next = {nx, ny, cur[2] + 1};
            q.push(next);
        }
    }

    for(int i = 0; i < M; i++)
    {
        cout << visited[mal[i][0]-1][mal[i][1]-1] - 1 << "\n";
    }
}