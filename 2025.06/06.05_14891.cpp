#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int k;
int chains[4][8];
bool visited[4];

void turn(int chainNum, int isClockwise)
{
    visited[chainNum] = true;
    
    if(chainNum+1 < 4 && !visited[chainNum+1])
    {
        if(chains[chainNum][2] != chains[chainNum+1][6])
        {
            turn(chainNum+1, -isClockwise);
        }
    }
    if(chainNum-1 >= 0 && !visited[chainNum-1])
    {
        if(chains[chainNum-1][2] != chains[chainNum][6])
        {
            turn(chainNum-1, -isClockwise);
        }
    }

    if(isClockwise == 1)
    {
        int temp = chains[chainNum][7];
        for(int i = 7; i >= 1; i--)
        {
            chains[chainNum][i] = chains[chainNum][i-1];
        }
        chains[chainNum][0] = temp;
    }
    else if(isClockwise == -1)
    {

        int temp = chains[chainNum][0];
        for(int i = 0; i < 7; i++)
        {
            chains[chainNum][i] = chains[chainNum][i+1];
        }
        chains[chainNum][7] = temp;
    }
}

int main()
{
    for(int i = 0; i < 4; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < 8; j++)
        {
            chains[i][j] = s[j] - '0';
        }
    }

    cin >> k;
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            visited[j] = false;
        }
        int t1, t2;
        cin >> t1 >> t2;
        turn(t1-1, t2);
    }

    int sol = 0;
    for(int i = 0; i < 4; i++)
    {
        sol += chains[i][0] * pow(2, i);
    }
    cout << sol;
}

