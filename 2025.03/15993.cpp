#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001][2];

// dp[i][0] 사용한 개수가 홀수
// dp[i][1] 사용한 개수가 짝수
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    dp[1][0] = 1; dp[1][1] = 0; // 1
    dp[2][0] = 1; dp[2][1] = 1; // 1+1 2
    dp[3][0] = 2; dp[3][1] = 2; // 1+2 2+1 1+1+1 3

    int t;
    cin >> t;
    int maxNum = 0;
    vector<int> arr;
    while(t--)
    {
        int n;
        cin >> n;
        maxNum = max(maxNum, n);
        arr.push_back(n);
    }

    int intMax = 1000000009;
    for(int i = 4; i < maxNum+1; i++)
    {
        dp[i][0] = ((dp[i-1][1] + dp[i-2][1]) % intMax + dp[i-3][1]) % intMax;
        dp[i][1] = ((dp[i-1][0] + dp[i-2][0]) % intMax + dp[i-3][0]) % intMax;
    }

    for(int i = 0; i < arr.size(); i++)
    {
        cout << dp[arr[i]][0] << " " << dp[arr[i]][1] << "\n";
    }

}