#include <iostream>
#include <vector>
#include <queue>

int INTMAX = 1e9;

using namespace std;


vector<pair<int, int>> road[20001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int V, E, S;
    cin >> V >> E;
    cin >> S;

    vector<int> dist(V+1);

    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        road[u].push_back(make_pair(v, w));
    }

    for(int i = 0; i <= V; i++)
    {
        dist[i] = INTMAX;
    }
    
    priority_queue<pair<int, int>> pq; // 거리, 노드
    pq.push(make_pair(0, S));
    dist[S] = 0;
    while(!pq.empty())
    {
        int curdist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(int i = 0; i < road[cur].size(); i++)
        {
            if(curdist + road[cur][i].second < dist[road[cur][i].first])
            {
                dist[road[cur][i].first] = curdist + road[cur][i].second;
                pq.push(make_pair(-dist[road[cur][i].first], road[cur][i].first));
            }
        }
    }

    for(int i = 1; i <= V; i++)
    {
        if(dist[i] == INTMAX)
        {
            cout << "INF" << "\n";
        }
        else
        {
            cout << dist[i] << "\n";
        }
    }
}