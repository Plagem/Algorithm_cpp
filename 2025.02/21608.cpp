#include <iostream>
#include <cmath>

using namespace std;

int N;
int map[21][21];
int classmate[401][5];
int mySeat[401][2];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void logic(int idx)
{
    int me = classmate[idx][0];

    int maxnear = 0, maxblank = 0, x = -1, y = -1;

    for(int i = 1 ; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(map[i][j] != 0) continue;

            if(x == -1)
            {
                x = i; y = j;
            }

            int tnear = 0, tblank = 0;
            for(int k = 0; k < 4; k++)
            {
                int nx = i + dx[k]; int ny = j + dy[k];
                if(0 < nx && nx <= N && 0 < ny && ny <= N)
                {
                    for(int o = 1; o < 5; o++)
                    {
                        if(map[nx][ny] == classmate[idx][o]) tnear++;
                    }
                    if(map[nx][ny] == 0) tblank++;
                }
            }

            if(tnear > maxnear)
            {
                x = i; y = j; maxnear = tnear; maxblank = tblank;
            }
            if(tnear == maxnear && tblank > maxblank)
            {
                x = i; y = j; maxblank = tblank;
            }
        }
    }

    map[x][y] = me;
    mySeat[me][0] = x; mySeat[me][1] = y;
}

int main()
{
    cin >> N;

    for(int i = 0; i < N*N; i++)
    {
        cin >> classmate[i][0] >> classmate[i][1] >> classmate[i][2] >> classmate[i][3] >> classmate[i][4];
    }

    for(int i = 0; i < N*N; i++)
    {
        logic(i);
    }
    int manjok = 0;

    for(int i = 0; i < N*N; i++)
    {
        int me = classmate[i][0];
        int x = mySeat[me][0]; int y = mySeat[me][1];

        int t = 0;
        for(int j = 0; j < 4; j++)
        {
            int nx = x + dx[j]; int ny = y + dy[j];
            if(0 < nx && nx <= N && 0 < ny && ny <= N)
            {
                for(int o = 1; o < 5; o++)
                {
                    if(map[nx][ny] == classmate[i][o]) t++;
                }
            } 
        }
        if(0 < t)
        {
            manjok += pow(10, t-1);
        }
    }

    cout << manjok;
}