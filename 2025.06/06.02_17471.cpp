#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int sol;
bool arr[10];
bool visited[10];
int person[10];
vector<int> g[10];

int e;

void input()
{
    sol = 1e9;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> person[i];
    }
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        for(int j = 0; j < t; j++)
        {
            int t2;
            cin >> t2;
            g[i].push_back(t2-1);
        }
    }
}

void bfs()
{
    fill(visited, visited+10, false);

    int white = 0, black = 0;
    int whiteidx = -1, blackidx = -1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == false)
        {
            whiteidx = i;
        }
        else
        {
            blackidx = i;
        }
    }
    
    if(whiteidx == -1 || blackidx == -1) return;

    queue<int> q;
    q.push(whiteidx); visited[whiteidx] = true;
    q.push(blackidx); visited[blackidx] = true;
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(int i = 0; i < g[cur].size(); i++)
        {
            if(arr[g[cur][i]] == arr[cur] && !visited[g[cur][i]])
            {
                visited[g[cur][i]] = true;
                q.push(g[cur][i]);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == false)
        {
            return;
        }

        if(arr[i] == true) white += person[i];
        else black += person[i];
    }

    sol = min(sol, abs(white - black));
}

void logic()
{
    int iter = pow(2, n);
    for(int i = 0; i < iter; i++)
    {
        bitset<10> bit(i);
        for(int j = 0; j < 10; j++)
        {
            arr[j] = bit[j];
        }
        bfs();
    }
}

int main()
{
    input();

    logic();

    if(sol == 1e9) cout << -1;
    else cout << sol;
}