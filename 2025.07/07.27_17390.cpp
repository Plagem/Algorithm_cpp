#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[300001];
int dp[300001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    } 
    sort(arr, arr+n);

    for(int i = 1; i <= n; i++)
    {
        dp[i] = dp[i-1] + arr[i-1];
    }

    for(int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        cout << dp[t2] - dp[t1-1] << "\n";
    }
}