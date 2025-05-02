// 2025.01.14
// DP

#include <iostream>

int pan[100];
int dp[10001];

using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // 팬 입력받기
    int N, M;
    cin >> N >> M;
    for(int i = 0; i <= 10000; i++) dp[i] = 99999;
    for(int i = 0; i < M; i++)
    {
        cin >> pan[i];
        dp[pan[i]] = 1;
    }
    dp[0] = 0;

    // 팬으로 만들 수 있는 경우의 수 입력받기
    for(int i = 0; i < M; i++)
    {
        for(int j = i+1; j < M; j++)
        {
            if(pan[i] + pan[j] > 10000) continue;

            dp[pan[i] + pan[j]] = 1;
        }
    }
    
    // dp 돌리기
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(dp[j] == 99999 || dp[i-j] == 99999) continue;
            dp[i] = min(dp[i], dp[j] + dp[i-j]);
        }
    }

    if(dp[N] == 99999) cout << "-1";
    else cout << dp[N];
}
