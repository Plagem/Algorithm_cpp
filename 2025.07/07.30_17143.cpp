// GRD - G1 17143 낚시왕
#include <iostream>
#include <vector>
using namespace std;
struct shark;

int kingPos = 0; // 낚시왕 위치 
int sol = 0; // 상어 크기의 합

int n, m, k;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<shark> arr[101][101];

struct shark
{
    int speed;
    int dir;
    int size;

    shark(int s, int d, int z) : speed(s), dir(d), size(z) {}
};

void catchFish(int col)
{
    int fishSize = 0;
    for(int row = 1; row <= n; row++)
    {
        if(arr[row][col].size())
        {
            fishSize = arr[row][col][0].size;
            arr[row][col].clear();
            break;
        }
    }
    sol += fishSize;
}

pair<int, int> Normalize(shark& tshark, int nx, int ny)
{
    int x, y;
    int xlength = (n - 1) * 2;
    int xidx = ((nx % (xlength)-1) + xlength) % xlength;
    x = xidx <= n-1 ? 1+xidx : n-(xidx-(n-1));

    int ylength = (m - 1) * 2;
    int yidx = ((ny % (ylength)-1) + ylength) % ylength;
    y = yidx <= m-1 ? 1+yidx : m-(yidx-(m-1));

    return {x, y};
}

void moveFish()
{
    vector<shark> tarr[101][101];

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(arr[i][j].size())
            {
                shark tshark = arr[i][j][0];
                arr[i][j].clear();

                int nx = i + dx[tshark.dir] * tshark.speed;
                int ny = j + dy[tshark.dir] * tshark.speed;
                pair<int, int> next = Normalize(tshark, nx, ny);
                pair<int, int> nnext = Normalize(tshark, nx + dx[tshark.dir], ny + dy[tshark.dir]);

                if(nnext.first - next.first != dx[tshark.dir] || nnext.second - next.second != dy[tshark.dir])
                {
                    if(tshark.dir < 2)
                    {
                        tshark.dir = (tshark.dir + 1) % 2;
                    }
                    else
                    {
                        tshark.dir = 2 + (tshark.dir-2 + 1) % 2;
                    }
                }

                nx = next.first; ny = next.second;

                tarr[nx][ny].push_back(tshark);
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(tarr[i][j].size() <= 1) continue;

            shark bigShark = tarr[i][j][0];
            for(int k = 1; k < tarr[i][j].size(); k++)
            {
                if(tarr[i][j][k].size > bigShark.size)
                {
                    bigShark = tarr[i][j][k];
                } 
            }

            tarr[i][j].clear();
            tarr[i][j].push_back(bigShark);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            arr[i][j] = tarr[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        shark tshark(s, d-1, z);
        arr[r][c].push_back(tshark);
    }

    for(int i = 1; i <= m; i++)
    {
        catchFish(i);
        moveFish();
    }

    cout << sol;
}