#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> v[2001];
bool visited[2001];

void dfs(int cur, int depth)
{
    if(depth == 5)
    {
        cout << 1;
        exit(0);
    }

    for(int i = 0; i < v[cur].size(); i++)
    {
        int next = v[cur][i];
        if(!visited[next])
        {
            visited[next] = true;
            dfs(next, depth+1);
            visited[next] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }

    for(int i = 0; i < n; i++)
    {
        visited[i] = true;
        dfs(i, 1);
        visited[i] = false;
    }

    cout << 0;
}