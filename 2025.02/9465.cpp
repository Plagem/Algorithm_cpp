#include <iostream>
#include <cstring>

using namespace std;

int arr[2][100000];
int dp[2][100000];

void Logic();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        Logic();
    }
}

void Logic()
{
    int N;
    cin >> N;

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int t;
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0]; dp[1][0] = arr[1][0];
    dp[0][1] = arr[1][0] + arr[0][1]; dp[1][1] = arr[0][0] + arr[1][1];
    for(int i = 2; i < N; i++)
    {
        dp[0][i] = max(dp[1][i-1] + arr[0][i], dp[1][i-2] + arr[0][i]);
        dp[1][i] = max(dp[0][i-1] + arr[1][i], dp[0][i-2] + arr[1][i]);
    }

    cout << max(dp[0][N-1], dp[1][N-1]) << '\n';
}