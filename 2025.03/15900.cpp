#include <queue>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> tree[500001];
bool visited[500001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    while(--n)
    {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    int sol = 0;

    stack<pair<int, int>> stack;
    stack.push(make_pair(1, 0));
    visited[1] = true;
    while(!stack.empty())
    {
        auto [cur, depth](stack.top()); stack.pop();
        for(int i = 0; i < tree[cur].size(); i++)
        {
            if(tree[cur].size() == 1) sol += depth;
            int next = tree[cur][i];
            if(visited[next]) continue;
            visited[next] = true;
            stack.push(make_pair(next, depth+1));
        }
    }

    cout << ((sol % 2 == 0) ? "No" : "Yes");
}