#include <queue>
#include <iostream>
#include <vector>

using namespace std;

vector<int> road[100001];
vector<int> parent(100001, -1);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N-1; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        road[t1].push_back(t2);
        road[t2].push_back(t1);
    }

    vector<bool> visited(100001, false);

    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(visited[cur]) continue;
        visited[cur] = true;

        for(int i = 0; i < road[cur].size(); i++)
        {
            if(parent[road[cur][i]] == -1)
            {
                parent[road[cur][i]] = cur;
            }
            q.push(road[cur][i]);
        }
    }

    for(int i = 2; i <= N; i++)
    {
        cout << parent[i] << "\n";
    }
}