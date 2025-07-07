#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int sol;
vector<pair<int, int>> v[501]; // {학생번호, 방향}
bool visited[501][501];

int main()
{
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v[t1].push_back({t2, 1}); // 1은 정방향
        v[t2].push_back({t1, 0}); // 0은 역방향
    }

    for(int i = 1; i <= n; i++)
    {
        visited[i][i] = true;
        queue<pair<int, int>> q;
        q.push({i, 1}); // 정방향 탐색
        q.push({i, 0}); // 역방향 탐색

        int acc = 1;
        while(!q.empty())
        {
            pair<int, int> cur = q.front(); q.pop();
            for(int j = 0; j < v[cur.first].size(); j++)
            {
                pair<int, int> next = v[cur.first][j];
                if(visited[i][next.first]) continue;

                if(next.second == cur.second) // 탐색 방향이 일치하면
                {
                    visited[i][next.first] = true;
                    q.push(next);
                    acc++;
                }
            }
        }
        if(acc == n) sol++;
    }

    cout << sol;
}