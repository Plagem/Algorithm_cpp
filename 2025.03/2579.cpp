#include <iostream>
using namespace std;

int n;
int stair[300];
int score[300];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> stair[i];
    }

    score[0] = stair[0];
    score[1] = stair[0] + stair[1];
    score[2] = max(stair[0]+stair[2], stair[1]+stair[2]);

    for(int i = 3; i < n; i++)
    {
        score[i] = max(score[i-2] + stair[i], score[i-3] + stair[i-1] + stair[i]);
    }
    cout << score[n-1];
}