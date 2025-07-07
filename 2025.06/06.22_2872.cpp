#include <iostream>
using namespace std;

int n;
int arr[300000];
int dp[300000];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cnt = n;
    for(int i = n-1; i >= 0; i--)
    {
        if(arr[i] == cnt)
        {
            cnt--;
        }
    }
    cout << cnt;
}