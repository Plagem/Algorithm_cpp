#include <iostream>
#include <cmath>
using namespace std;

int n;
int dp[50001];

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        if(floor(sqrt(i)) == sqrt(i))
        {
            dp[i] = 1;
        }
        else
        {
            int j = 1;
            while(j*j <= i)
            {
                if(dp[i - j*j] != 0)
                {

                    if(dp[i] == 0)
                        dp[i] = dp[i - j*j] + 1;
                    else
                        dp[i] = min(dp[i], dp[i - j*j] + 1);
                }
                j++;
            }
        }
    }


    cout << dp[n];
}