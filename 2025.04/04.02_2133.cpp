// 2133 타일 채우기 : DP
#include <iostream>
using namespace std;

int n;
int sol;
int dp[31];

int main()
{
    cin >> n;

    dp[0] = 1; dp[1] = 0; dp[2] = 3;

    if(n%2 == 1)
    {
        sol = 0;
    }
    else
    {
        for(int i = 4; i <= n; i += 2)
        {
            dp[i] = dp[i-2] * dp[2];
            for(int j = i - 4; j >= 0; j -= 2)
            {
                dp[i] = dp[i] + dp[j]*2;
            }
        }
        sol = dp[n];
    }

    cout << sol;
}