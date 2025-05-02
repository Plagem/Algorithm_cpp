#include <iostream>
using namespace std;

int tetromino[19][4][2] = 
{
    // 세로 2개
    {{0,0}, {0,1}, {0,2}, {0,3}},
    {{0,0}, {1,0}, {2,0}, {3,0}},
    // 네모 1개
    {{0,0}, {0,1}, {1,0}, {1,1}},
    // L자 8개
    {{0,0}, {1,0}, {2,0}, {2,1}},
    {{0,1}, {1,1}, {2,1}, {2,0}},
    {{1,0}, {1,1}, {1,2}, {0,2}},
    {{0,0}, {1,0}, {1,1}, {1,2}},
    {{0,0}, {0,1}, {1,1}, {2,1}},
    {{0,0}, {0,1}, {1,0}, {2,0}},
    {{0,0}, {1,0}, {0,1}, {0,2}},
    {{0,0}, {0,1}, {0,2}, {1,2}},
    // S자 4개
    {{0,0}, {1,0}, {1,1}, {2,1}},
    {{1,0}, {1,1}, {0,1}, {0,2}},
    {{0,1}, {1,1}, {1,0}, {2,0}},
    {{0,0}, {0,1}, {1,1}, {1,2}},
    // ㅗ자 4개
    {{0,0}, {0,1}, {1,1}, {0,2}},
    {{0,0}, {1,0}, {2,0}, {1,1}},
    {{0,1}, {1,1}, {2,1}, {1,0}},
    {{1,0}, {1,1}, {0,1}, {1,2}}
};

int arr[500][500];

int main()
{
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    int sol = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            for(int tet = 0; tet < 19; tet++)
            {
                bool canStack = true;
                for(int k = 0; k < 4; k++)
                {
                    int nx = i + tetromino[tet][k][0];
                    int ny = j + tetromino[tet][k][1];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) canStack = false;
                }
                if(canStack)
                {
                    int temp = 0;
                    for(int k = 0; k < 4; k++)
                    {
                        int nx = i + tetromino[tet][k][0];
                        int ny = j + tetromino[tet][k][1];
                        temp += arr[nx][ny];
                    }
                    sol = max(sol, temp);
                }
            }
        }
    }

    cout << sol;
}