#include <iostream>

using namespace std;
int main()
{
    int com[15][8] = {0,};
    int stack = 0;
    int num = 1;

    for(int i = 0; i < 120; i++)
    {
        com[i%15][i/15] = num;
        stack++;
        if(stack == 6)
        {
            stack = 0;
            num++;
        }
    }

    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            cout << com[i][j] << " ";
        }
        cout << endl;
    }
}