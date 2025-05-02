#include<iostream>
#include<string>


int arr[2000][2];

using namespace std;
int main()
{
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    int x = 0, y = 0;
    for(int i = 0; i < N; i++)
    {
        switch(S[i])
        {
            case 'U':
            y++;
            break;
            case 'R':
            x++;
            break;
            case 'L':
            x--;
            break;
            case 'D':
            y--;
            break;
        }
        arr[i][0] = x; arr[i][1] = y;
    }
    int lx = x, ly = y;

    for(int i = 0; i < min(N, K); i++)
    {
        for(int j = 0; j < N; j++)
        {           
            if(arr[j][0] + lx * i == 0 && arr[j][1] + ly * i == 0)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}