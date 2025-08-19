#include <iostream>
#include <vector>
using namespace std;

int scenario = 1;
int t; 
int n, k, m;
int parent[100001];

int Find(int idx)
{
    if(parent[idx] == idx)
    {
        return idx;
    }
    return parent[idx] = Find(parent[idx]);
}

void Union(int idx1, int idx2)
{
    if(Find(idx1) != Find(idx2))
    {
        parent[Find(idx2)] = Find(idx1);
    }
}

void logic()
{
    cin >> n >> k;

    for(int i = 0; i < 100001; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < k; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        Union(t1, t2);
    }

    cin >> m;

    vector<int> sol;
    for(int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        if(Find(t1) == Find(t2))
        {
            sol.push_back(1);
        }
        else
        {
            sol.push_back(0);
        }
    }

    cout << "Scenario " << scenario << ": \n";
    for(int i = 0; i < m; i++)
    {
        cout << sol[i] << "\n";
    }
    cout << "\n";
}

int main()
{
    cin >> t;
    while(t--)
    {
        logic();
        scenario++;
    }
}