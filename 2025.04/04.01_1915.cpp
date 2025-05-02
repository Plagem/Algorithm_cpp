// 1915 가장 큰 정사각형 : 구간합
#include <iostream>
#include <string>
using namespace std;

int curMaxEdge = 1;
int n, m;
int pSum[1001][1001];

// (x,y)에서 시작하고 길이가 edge인 정사각형이 존재하는지 여부를 bool로 return
bool checkSqare(int x, int y, int edge)
{
    if(x+edge-1 > n || y+edge-1 > m)
        return false;
    
    if(pSum[x+edge-1][y+edge-1] - pSum[x+edge-1][y-1] - pSum[x-1][y+edge-1] + pSum[x-1][y-1] == edge* edge)
        return true;

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        for(int j = 1; j <= m; j++)
        {
            // Prefix Sum Algorithm
            pSum[i][j] = pSum[i][j-1] + pSum[i-1][j] - pSum[i-1][j-1] + (temp[j-1] - '0');
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            while(checkSqare(i, j, curMaxEdge))
            {
                curMaxEdge++;
            }
        }
    }

    cout << (curMaxEdge-1) * (curMaxEdge-1);
}