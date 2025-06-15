#include <iostream>
using namespace std;

int arr[19][19];
int result;
int rx, ry;

int dx[4] = {-1, 0, 1, 1};
int dy[4] = {1, 1, 1, 0};

void print()
{
    if(result)
    {
        cout << result << endl;
        cout << rx+1 << " " << ry+1;
    }
    else
    {
        cout << result;
    }
}

void input()
{
    for(int i = 0; i < 19; i++)
        for(int j = 0; j < 19; j++)
            cin >> arr[i][j];
}

void logic()
{
    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            if(arr[i][j] == 0) continue;
            for(int d = 0; d < 4; d++)
            {
                int com = 0;
                for(int it = -1; it < 6; it++)
                {
                    int nx = i + dx[d]*it;
                    int ny = j + dy[d]*it;
                    if(0 > nx || 19 <= nx || 0 > ny || 19 <= ny) continue;
                    
                    if(0 <= it && it < 5)
                    {
                        com++;
                        if(arr[i][j] != arr[nx][ny]) com = 0;
                    }
                    else
                    {
                        if(arr[i][j] == arr[nx][ny])
                        {
                            com = 0; break;
                        }
                    }
                }
                if(com == 5)
                {
                    result = arr[i][j];
                    rx = i; ry = j;
                    return;
                }
            }
        }
    }
}

int main()
{
    input();
    logic();
    print();
}