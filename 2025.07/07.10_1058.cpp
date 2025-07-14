#include <iostream>
#include <queue>
using namespace std;

int n;
int dist[51][51];

void floyd()
{
    for(int m = 0; m < n; m++)
    {
        for(int s = 0; s < n; s++)
        {
            for(int e = 0; e < n; e++)
            {
                if(dist[s][e] > dist[s][m]  + dist[m][e])
                {
                    dist[s][e] = dist[s][m] + dist[m][e];
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++)
        {  
            if(s[j] =='N')
            {
                dist[i][j] = 1e9;
            }
            else
            {
                dist[i][j] = 1;
            }
        }
        dist[i][i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        floyd();
    }

    int sol = 0;
    for(int i = 0; i < n; i++)
    {
        int tmp = 0;
        for(int j = 0; j < n; j++)
        {
            if(dist[i][j] <= 2 && dist[i][j] != 0)
            {
                tmp++;
            }
        }
        sol = max(sol, tmp);
    }

    cout << sol;
}