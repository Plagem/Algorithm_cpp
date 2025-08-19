#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

int v, e;
int arr[401][401];

int main()
{
    for(int i = 0; i <= 400; i++)
    {
        for(int j = 0; j <= 400; j++)
        {
            arr[i][j] = INF;
        }
    }

    cin >> v >> e;
    for(int i = 0; i < e; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        arr[t1][t2] = t3;
    }

    for(int m = 1; m <= v; m++)
    {
        for(int s = 1; s <= v; s++)
        {
            for(int e = 1; e <= v; e++)
            {
                if(arr[s][e] > arr[s][m] + arr[m][e])
                    arr[s][e] = arr[s][m] + arr[m][e];
            }
        }
    }

    int sol = INF;
    for(int s = 1; s <= v; s++)
    {
        for(int m = 1; m <= v; m++)
        {
            if(arr[s][m] != INF && arr[m][s] != INF)
            sol = min(sol, arr[s][m] + arr[m][s]);
        }
    }

    if(sol == INF) cout << "-1";
    else cout << sol;
}