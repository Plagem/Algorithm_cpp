//P5 1799 비숍 : 백트래킹, 구현
#include <iostream>
#include <vector>
using namespace std;

int n;
int maxBishop = 0;
int board[10][10];
bool bishopList[19];

vector<pair<int, int>> bishops;

void nBishop(int x, int y)
{
    if(bishops.size() > maxBishop)
    {
        maxBishop = bishops.size();
    }

    for(int i = x*n+y; i < n*n; i++)
    {
        int row = i / n; int col = i % n;

        if(bishopList[(row-col)+n-1]) continue;
        if(board[row][col] == 0) continue;

        bool canPosition = true;
        for(auto bishop : bishops)
        {
            if(abs(bishop.first-row) == abs(bishop.second-col))
            {
                canPosition = false; break;
            }
        }

        if(canPosition)
        {
            bishops.push_back(make_pair(row, col));
            bishopList[(row-col)+n-1] = true;
            nBishop(row, col);
            bishopList[(row-col)+n-1] = false;
            bishops.pop_back();
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    nBishop(0,0);

    cout << maxBishop;
}