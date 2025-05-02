#include <iostream>
#include <queue>

using namespace std;

int n;
int board[20][20];

int dx[4] = {0, 0, 0, 0};
int dy[4] = {0, 0, 0, 0};

enum Dir
{
    Up,
    Down,
    Right,
    Left,
};

void merge(Dir dir)
{
    for(int i = 0; i < n; i++)
    {
        queue<int> mergequeue;
        vector<int> saving;

        switch(dir)
        {
            case Up:
            {
                for(int j = 0; j < n; j++)
                {
                    if(board[j][i] != 0)
                    {
                        if(!mergequeue.empty())
                        {
                            if(mergequeue.front() == board[j][i])
                            {
                                mergequeue.pop();
                                saving.push_back(board[j][i] * 2);    
                            }
                            else
                            {
                                saving.push_back(mergequeue.front());
                                mergequeue.pop();
                                mergequeue.push(board[j][i]);
                            }
                        }
                        board[j][i] = 0;
                    }
                }
            }
            case Down:
            {

            }
            case Right:
            {

            }
            case Left:
            {

            }
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
}