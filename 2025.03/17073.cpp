#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> node[500001];
vector<bool> visited(500001);
int leaf = 0;

int main()
{
    int n, w;
    cin >> n >> w;

    // Make Tree
    for(int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    // Logic
    queue<int> tree;
    tree.push(1);
    visited[1] = true;
    while(!tree.empty())
    {
        int cur = tree.front(); tree.pop();
        // 일단 리프면 간선 1개고.. 부모 방문했을거니까 부모가 true면 리프겠죠?
        if(node[cur].size() == 1 && visited[node[cur][0]] == true)
        {
            leaf++;
        }
        for(int i = 0; i < node[cur].size(); i++)
        {
            if(!visited[node[cur][i]])
            {
                visited[node[cur][i]] = true;
                tree.push(node[cur][i]);
            }
        }
    }

    double dLeaf = (double)leaf;
    double dWater = (double)w;
    cout.precision(6);
    cout << fixed << dWater/dLeaf;
}