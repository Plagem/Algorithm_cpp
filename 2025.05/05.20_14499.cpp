#include <iostream>
using namespace std;

int n, m, x, y, k;
int dice[6];
int arr[21][21];
int input[1001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int change[4][6] = {
    {3, 1, 0, 5, 4, 2},
    {2, 1, 5, 0, 4, 3},
    {4, 0, 2, 3, 5, 1},
    {1, 5, 2, 3, 0, 4}
};

void updateDice(int dir)
{
    // 2     - arr[1]
    //413    - arr[3] - arr[0] - arr[2]
    // 5     - arr[4]
    // 6     - arr[5]

    // 1
    //530
    // 4
    // 2

    // 윗면은 arr[0] 아랫면은 arr[5]

    int newdice[6];
    for(int i = 0; i < 6; i++)
    {
        newdice[i] = dice[change[dir][i]];
    }
    for(int i = 0; i < 6; i++)
    {
        dice[i] = newdice[i];
    }
}

int main()
{
    cin >> n >> m >> x >> y >> k;
    for(int i = 0.; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < k; i++)
    {
        cin >> input[i];
        input[i]--;
    }

    for(int i = 0; i < k; i++)
    {
        int nx = x + dx[input[i]];
        int ny = y + dy[input[i]];
        if(0 <= nx && nx < n && 0 <= ny && ny < m)
        {
            x = nx;
            y = ny;
            updateDice(input[i]);
            if(arr[x][y] == 0)
            {
                arr[x][y] = dice[5];
            }
            else
            {
                dice[5] = arr[x][y];
                arr[x][y] = 0;
            }
            cout << dice[0] << '\n';
        }
    }
}