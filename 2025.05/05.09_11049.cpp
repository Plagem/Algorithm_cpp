#include <iostream>
#include <vector>
using namespace std;

int n;
int dp[501][501];
pair<int, int> matrix[501];

void input()
{
    fill(&dp[0][0], &dp[501][501], 1e9);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int r, c;
        cin >> r >> c;
        matrix[i] = make_pair(r, c);
        dp[i][i] = 0;
    }
}

int main()
{
    input();

    // i는 간격
    for(int i = 1; i <= n-1; i++)
    {   
        // j는 시작점
        for(int j = 1; j + i <= n; j++)
        {
            int start = j; int end = j+i;
            if(end > n)
            {
                cout << "kj";
            }
            // k는 중간점
            for(int k = 0; k < i; k++)
            {
                dp[start][end] = min(dp[start][end], dp[start][start+k] + dp[start+k+1][end] + matrix[start].first * matrix[start+k].second * matrix[end].second);
            }
        }
    }

    cout << dp[1][n];
}
