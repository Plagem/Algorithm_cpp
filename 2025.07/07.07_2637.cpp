#include <iostream>
#include <vector>
using namespace std;

int n, m;
int sol[101];
bool visited[101];
vector<pair<int, int>> info[101];

void logic()
{
    while(true)
    {
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                bool canCheck = true;
                vector<int> newInf(101);
                vector<pair<int, int>> newInfo;
                for(int j = 0; j < info[i].size(); j++)
                {
                    int part = info[i][j].first;
                    int num = info[i][j].second;
                    if(!visited[part])
                    {
                        canCheck = false;
                        break;
                    }
                    else
                    {
                        for(int k = 0; k < info[part].size(); k++) 
                        {
                            newInf[info[part][k].first] += info[part][k].second * num;
                        }
                    }
                }
                if(canCheck)
                {
                    for(int j = 1; j <= 100; j++)
                    {
                        if(newInf[j] > 0)
                        {
                            newInfo.push_back({j, newInf[j]});
                        }
                    }
                    info[i] = newInfo;
                    visited[i] = true;
                    if(i == n) return;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        info[t1].push_back({t2, t3});
        // 즉, info[a].size() == 0 이라면 기본부품이다.
    }

    for(int i = 1; i <= n; i++)
    {
        if(info[i].size() == 0)
        {
            info[i].push_back({i, 1});
            visited[i] = true;
        }
    }

    logic();

    vector<int> sol(101);

    for(int i = 0; i < info[n].size(); i++)
    {
        if(info[n][i].second > 0)
        {
            sol[info[n][i].first] = info[n][i].second;
        }
    }

    for(int i = 1; i <= 100; i++)
    {
        if(sol[i] > 0)
        {
            cout << i << " " << sol[i] << endl;
        }
    }
}