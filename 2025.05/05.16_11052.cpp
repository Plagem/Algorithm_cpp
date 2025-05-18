#include <iostream>
#include <vector>
using namespace std;

int n;
int dp[1001];
int card[1001];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> card[i];
    }

    dp[1] = card[1];
    for(int i = 2; i <= n; i++)
    {
        dp[i] = card[i];
        for(int j = 1; j < i; j++)
        {
            dp[i] = max(dp[i], dp[j] + dp[i-j]);
        }
    }
    
    cout << dp[n];
}