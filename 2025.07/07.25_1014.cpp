#include <iostream>
using namespace std;
typedef long long ll;

int n, k;
ll all = 1;

string sarr[15];
int arr[15];
int dp[1<<15][3];

int main()
{
    // 입력
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> sarr[i];
        all *= i+1;
    }
    cin >> k;

    // arr 후처리
    for(int i = 0; i < n; i++)
    {
        int t = 0;
        for(int j = 0; j < sarr[i].size(); j++)
        {
            int c = sarr[i][j] - '0';
            t = (t*10 + c) % k;
        }
        arr[i] = t;
    }

    // dp

}