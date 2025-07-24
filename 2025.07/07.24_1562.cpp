#include <iostream>
using namespace std;

int n, sol;
int dp[10][101][10][10];

int main()
{
    cin >> n;

    for(int i = 0; i <= 9; i++)
    {
        dp[i][1][i][i] = 1;
    }

    for(int j = 2; j <= n; j++) // 길이는 j
    {
        for(int i = 0; i <= 9; i++) // i로 시작하는 계단수
        {
            for(int k = 0; k <= 9; k++) // 계단수 범위의 시작점은 k
            {
                for(int l = k; l <= 9; l++) // 계단수 범위의 끝점은 l
                {
                    if(k > i || l < i) continue; // 시작점, 끝점이 범위에 없다면 pass

                    if(i != 0)
                    {
                        // 이전 계단수 범위 k~l인거 더해주기
                        dp[i][j][k][l] += dp[i-1][j-1][k][l];
                    }
                    if(i != 9)
                    {
                        // 이전 계단수 범위 k~l인거 더해주기
                        dp[i][j][k][l] += dp[i+1][j-1][k][l];
                    }

                    if(l == i && l != 0 && i != 0) // 끝점이 i와 같다면
                    {
                        // 이전 계단수 범위 k~(i-1)인거 더해주기
                        dp[i][j][k][l] += dp[i-1][j-1][k][i-1];
                    }
                    if(k == i && k != 9 && i != 9)
                    {
                        // 이전 계단수 범위 (i+1)~l인거 더해주기
                        // 범위 (i+1)~l이려면 이전 계단수의 수가 i보다 커야한다
                        dp[i][j][k][l] += dp[i+1][j-1][i+1][l];
                    }
                }
            }
        }
    }

    for(int i = 1; i <= 9; i++)
    {
        sol += dp[i][n][0][9];
        sol = sol % 1000000000;
    }

    cout << sol;
}