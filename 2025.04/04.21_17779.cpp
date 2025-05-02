#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int arr[21][21];
int divArr[21][21];
bool visited[21][21];

int n;
int vote[5];

bool makeDivArr(int x, int y, int d1, int d2)
{
    // 일단 만드는게 가능한지 판단 때린다
}

void bfs()
{
    // 만들어진 divArr 활용해서 bfs
}

void input()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int main()
{
    input();
}