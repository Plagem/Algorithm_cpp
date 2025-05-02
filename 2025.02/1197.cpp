#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> Edges[10001];
bool visited[10001];
vector<pair<int, int>> MST;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int V, E;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int S, E, C;
        cin >> S >> E >> C;
        Edges[S].push_back(make_pair(C, E));
        Edges[E].push_back(make_pair(C, S));
    }

    pq.push(make_pair(0, 1));
    while(!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();

        if(visited[cur.second]) continue;
        visited[cur.second] = true;
        MST.push_back(make_pair(cur.first, cur.second));

        for(int i = 0; i < Edges[cur.second].size(); i++)
        {
            int next = Edges[cur.second][i].second;
            int nextcost = Edges[cur.second][i].first;
            pq.push(make_pair(nextcost, next));
        }
    }

    int sol = 0;
    for(int i = 0; i < MST.size(); i++)
    {
        sol += MST[i].first;
    }

    cout << sol;
}