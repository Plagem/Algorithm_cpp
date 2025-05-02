// 2025.01.11 
// knapsack 문제

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>


long long damage[49];
long long boss[13][2];
long long ans[49];

bool rev(long long a, long long b)
{
    return a > b;
}

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
    {
        cin >> damage[i];
    }

    for(int i = 0; i < K; i++)
    {
        //0은 체력 1은 보상
        cin >> boss[i][0] >> boss[i][1];
    }

    //캐릭터별로 냅색 들어가기
    for(int i = 0; i < N; i++)
    {
        long long dmg = damage[i];        
        long long dp[50][901] = {0, };

        for(int j = 1; j <= K; j++)
        {
            // 몬스터별 소모값 기록
            long long time = boss[j-1][0] / dmg;
            if(boss[j-1][0] % dmg != 0) time++;
            long long meso = boss[j-1][1];

            for(int k = 1; k <= 900; k++)
            {
                if(k >= time)
                {
                    dp[j][k] = max(dp[j-1][k], dp[j-1][k-time] + meso);
                }
                else
                {
                    dp[j][k] = dp[j-1][k];
                }
            }
        }
        ans[i] = dp[K][900];
    }

    // 정답 출력
    sort(ans, ans + 49, rev);

    long long solMeso = 0;
    for(int i = 0; i < M; i++)
    {
        solMeso += ans[i];
    }

    cout << solMeso;
}