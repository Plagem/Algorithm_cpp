#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int NodeMax = 10001;
bool visited[10001];

int tmax = 0;
int maxidx = 0;

vector<pair<int, int>> Edges[10001];

void dfs(int start, int sum)
{
    if(visited[start]) return;
    visited[start] = true;

    if(tmax < sum)
    {
        maxidx = start;
        tmax = sum;
    }

    for(int i= 0; i < Edges[start].size(); i++)
    {
        dfs(Edges[start][i].first, sum + Edges[start][i].second);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N-1; i++)
    {
        int S, E, W;
        cin >> S >> E >> W;

        Edges[S].push_back(make_pair(E, W));
        Edges[E].push_back(make_pair(S, W));
    }

    dfs(1, 0);
    tmax = 0;
    for(int i = 1; i <= N; i++) visited[i] = false;
    dfs(maxidx, 0);

    cout << tmax;
}

