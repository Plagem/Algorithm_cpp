#include <iostream>
#include <vector>
using namespace std;

int n;
bool visited[10];
int arr[10][10];
int sol = 1e9;

void dfs(int depth, int cur, int prev, int cost)
{
    if(depth == n)
    {
        if(arr[prev][cur] == 0) return;
        cost += arr[prev][cur];
        sol = min(sol, cost);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i] || arr[prev][i] == 0) continue;
        visited[i] = true;
        dfs(depth+1, cur, i, cost + arr[prev][i]);
        visited[i] = false;   
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        visited[i] = true;
        dfs(1, i, i, 0);
        visited[i] = false;
    }

    cout << sol;
}