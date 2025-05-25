#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll arr[6];
ll sq[4][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                cin >> sq[i][j];
            }
        }

        int n = 0;
        for(int i = 0; i < 4; i++)
        {
            for(int j = i+1; j < 4; j++)
            {
                arr[n] = (sq[i][0] - sq[j][0]) * (sq[i][0] - sq[j][0]) + (sq[i][1] - sq[j][1]) * (sq[i][1] - sq[j][1]);
                n++;
            }
        }

        sort(arr, arr+6);

        if(arr[0] == arr[1] && arr[2] == arr[3] && arr[0] == arr[3])
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
        }
    }
}
