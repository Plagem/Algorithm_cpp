#include <iostream>
using namespace std;

int n;
int dp[1001]; // 연속 저장
int arr[1001];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++)
    {
        int m = 0;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
            {
                m = max(m, dp[j]+arr[i]);
            }
        }
        dp[i] = m;
    }

    int sol = 0;
    for(int i = 0; i <= n; i++)
    {
        sol = max(sol, dp[i]);
    }

    cout << sol;
}