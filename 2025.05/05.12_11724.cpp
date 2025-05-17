#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, sol;
vector<int> graph[1001];
bool visited[1001];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(int i = 0; i < graph[cur].size(); i++)
        {
            if(!visited[graph[cur][i]])
            {
                q.push(graph[cur][i]);
                visited[graph[cur][i]] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            bfs(i);
            sol++;
        }
    }

    cout << sol;
}