#include <iostream>
using namespace std;

int dp[5][5][100005];

int main()
{
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 100005; k++)
                dp[i][j][k] = 1e9;

    dp[0][0][0] = 0;

    int idx = 0;
    while(true)
    {
        int t;
        cin >> t;
        if(t == 0)
        {
            int m = 1e9;
            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    if(dp[i][j][idx] != 1e9)
                        m = min(m, dp[i][j][idx]);
                }
            }
            cout << m;
            break;
        }
        
        idx++;
    
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(dp[i][j][idx-1] != 1e9) // 이전의 기록이 있을 경우
                {
                    if(i == t || j == t) // 1을 소모하여 더블탭
                    {
                        dp[i][j][idx] = min(dp[i][j][idx], dp[i][j][idx-1] + 1);
                    }
                    else // 새로운 발판으로 움직이기
                    {
                        // 왼발 무빙
                        if(i == 0)
                        {
                            dp[t][j][idx] = min(dp[t][j][idx], dp[i][j][idx-1] + 2);
                        }
                        else
                        {
                            int plus = abs(i - t) == 2 ? 4 : 3;
                            dp[t][j][idx] = min(dp[t][j][idx], dp[i][j][idx-1] + plus);
                        }
                        // 오른발 무빙
                        if(j == 0)
                        {
                            dp[i][t][idx] = min(dp[i][t][idx], dp[i][j][idx-1] + 2);
                        }
                        else
                        {
                            int plus = abs(j - t) == 2 ? 4 : 3;
                            dp[i][t][idx] = min(dp[i][t][idx], dp[i][j][idx-1] + plus);
                        }
                    }  
                }
            }
        }
    }
}