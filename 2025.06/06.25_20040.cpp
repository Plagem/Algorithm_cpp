#include <iostream>
using namespace std;

int n, m;
int parent[5000000];
int sol;

int find(int u)
{
    if(parent[u] == u) return u;
    else return parent[u] = find(parent[u]);
}

bool doUnion(int u, int v)
{
    u = find(u);
    v = find(v);

    if(u == v) return true;
    else
    {
        parent[u] = v;
        return false;
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for(int i = 1; i <= m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;

        if(doUnion(t1, t2))
        {
            sol = i;
            break;
        }
    }

    if(sol == 0) cout << 0;
    else cout << sol;
}