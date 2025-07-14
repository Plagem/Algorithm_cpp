#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[300][300];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int sol = 0;
    while(true)
    {
        int numIce = 0;
        int sx = -1, sy = -1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] > 0)
                {
                    numIce++;
                    sx = i; sy = j;
                }
            }
        }

        if(sx == -1 && sy == -1) break;

        int acc = 0;
        bool visited[300][300] = {};
        queue<pair<int, int>> q;
        q.push({sx, sy});
        visited[sx][sy] = true;
        while(!q.empty())
        {
            acc++;
            pair<int, int> cur = q.front();
            q.pop();

            int bada = 0;
            for(int i = 0; i < 4; i++)
            {
                pair<int, int> next = {cur.first+dx[i], cur.second+dy[i]};
                if(!visited[next.first][next.second])
                {
                    if(arr[next.first][next.second] > 0)
                    {
                        q.push(next);
                        visited[next.first][next.second] = true;
                    }
                    else
                        bada++;
                }
            }
            arr[cur.first][cur.second] = max(0, arr[cur.first][cur.second]-bada);
        }

        if(acc != numIce)
        {
            cout << sol;
            exit(0);
        }
        sol++;
    }

    cout << "0";
}