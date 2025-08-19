#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int visited[100001];

vector<pair<int, int>> road[100001];

struct comp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int start = 0;

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int t1, t2, c;
        cin >> t1 >> t2 >> c;
        start = t1;
        road[t1].push_back({t2, c});
        road[t2].push_back({t1, c});
    }

    visited[start] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> q;
    for(int i = 0; i < road[start].size(); i++)
    {
        q.push(road[start][i]);
    }

    int sol = 0;
    int mm = 0;
    while(!q.empty())
    {
        pair<int, int> cur = q.top();
        q.pop();
        if(visited[cur.first]) continue;

        sol += cur.second;
        mm = max(mm, cur.second);
        
        visited[cur.first] = true;
        for(int i = 0; i < road[cur.first].size(); i++)
        {
            if(!visited[road[cur.first][i].first])
            {
                q.push(road[cur.first][i]);
            }
        }
    }

    cout << sol - mm;
}