#include <iostream>
using namespace std;

int n, sol;
int dp[10][101]; //dp[5][3] 은 5로 시작하고 길이 3인 인접수의 개수

int main()
{
    cin >> n;

    for(int i = 0; i <= 9; i++)
    {
        dp[i][1] = 1;
    }

    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            if(j > 0)
            {
                dp[j][i] += dp[j-1][i-1];
            }
            if(j < 9)
            {
                dp[j][i] += dp[j+1][i-1];
            }
            dp[j][i] = dp[j][i] % 1000000000;
        }
    }


    for(int i = 1; i <= 9; i++)
    {
        sol += dp[i][n];
        sol = sol % 1000000000;
    }

    cout << sol;
}