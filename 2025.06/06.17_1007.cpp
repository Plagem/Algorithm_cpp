#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> vec;
bool visited[21];
double sol = 1e9;

void calc()
{
    double accx = 0, accy = 0;

    for(int i = 0; i < n; i++)
    {
        if(visited[i])
        {
            accx += vec[i].first;
            accy += vec[i].second;
        }
        else
        {
            accx -= vec[i].first;
            accy -= vec[i].second;
        }
    }

    double temp = sqrt((accx * accx) + (accy * accy));
    if(sol > temp)
    {
        sol = temp;
    }
}

void dfs(int idx, int depth)
{
    if(depth == n/2)
    {
        calc();
        return;
    }

    for(int i = idx; i < n; i++)
    {
        visited[i] = true;
        dfs(i+1, depth+1);
        visited[i] = false;
    }
}

void logic()
{
    sol = 1e9;
    vec.clear();

    cin >> n;
    int t1, t2;
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
        cin >> t1 >> t2;
        vec.push_back({t1, t2});
    }

    dfs(0, 0);

    printf("%.7lf\n", sol);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        logic();
    }
}