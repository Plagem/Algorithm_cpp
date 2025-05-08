#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[500][500];

int dx[10] = {-2, -1, -1, -1, 0, 1, 1, 1, 2, 0};
int dy[10] = {0, -1, 0, 1, -2, -1, 0, 1, 0, -1};
float dper[10] = {0.02, 0.1, 0.07, 0.01, 0.05, 0.1, 0.07, 0.01, 0.02, 0.55};

int dxVec[4] = {0, 1, 0, -1};
int dyVec[4] = {-1, 0, 1, 0};

int sol = 0;
int curX, curY;
int vecIdx = 0;
int curSize = 1;
int go, turn;

void sandWind(int vec)
{
    int total = arr[curX][curY];
    int ndx, ndy;
    for(int i = 0; i < 10; i++)
    {
        switch(vec)
        {
            case 0:
                ndx = dx[i]; ndy = dy[i];
                break;
            case 1:
                ndx = -dy[i]; ndy = dx[i];
                break;
            case 2:
                ndx = dx[i]; ndy = -dy[i];
                break;
            case 3:
                ndx = dy[i]; ndy = -dx[i];
                break;
        }

        int ssand;
        if(i < 9)
        {
            ssand = arr[curX][curY] * dper[i];
            total -= ssand;
        }
        else
        {
            ssand = total;
        }

        int nx = curX + ndx; int ny = curY + ndy;
        if(0 <= nx && nx < n && 0 <= ny && ny < n)
        {
            arr[nx][ny] += ssand;
        }
        else
        {
            sol += ssand;
        }
    }
    arr[curX][curY] = 0;
}

void moveToNextPos()
{
    curX += dxVec[vecIdx];
    curY += dyVec[vecIdx];
    sandWind(vecIdx);
    go++;
    if(go >= curSize)
    {
        go = 0;
        vecIdx++; vecIdx %= 4;
        if(vecIdx%2 == 0)
        {
            curSize++;
        }        
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    curX = n/2; curY = n/2;

    for(int i = 0; i < n*n-1; i++)
    {
        moveToNextPos();
    }

    cout << sol;
}