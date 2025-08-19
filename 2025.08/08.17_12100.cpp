#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int sol;

int n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void printBoard(const vector<vector<int>>& prevBoard)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << prevBoard[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<vector<int>> moveBoard(const vector<vector<int>>& prevBoard, int dir)
{
    vector<vector<int>> curBoard(n, vector<int>(n));

    for(int i = 0; i < n; i++)
    {
        queue<int> q;        
        for(int j = 0; j < n; j++)
        {
            int x, y;
            switch(dir)
            {
                case 0:
                x = j; y = i; break;
                case 1:
                x = n-1-j; y = i; break;
                case 2:
                x = i; y = j; break;
                case 3:
                x = i; y = n-1-j; break;
            }

            if(prevBoard[x][y] != 0)
            {
                q.push(prevBoard[x][y]);
            }
        }

        int idx = dir % 2 == 0 ? 0 : n-1;
        
        while(!q.empty())
        {
            int first = q.front(); q.pop();
            int second = 0;
            if(!q.empty())
            {
                second = q.front();
            }

            int x = dir < 2 ? idx : i;
            int y = dir < 2 ? i : idx;

            if(first == second)
            {
                q.pop();
                curBoard[x][y] = first * 2;
            }
            else
            {
                curBoard[x][y] = first;
            }
            sol = max(sol, curBoard[x][y]);
    
            idx = dir % 2 == 0 ? idx+1 : idx-1;
        }
    }


    return curBoard;
}

void dfs(const vector<vector<int>>& tBoard, int depth)
{
    if(depth == 10)
    {
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        vector<vector<int>> newBoard = moveBoard(tBoard, i);
        //cout << depth;
        dfs(newBoard, depth+1);
    }
}

int main()
{
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    dfs(board, 0);

    cout << sol;
}