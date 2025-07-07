#include <iostream>
using namespace std;

int n;
int arr[1001];
int dp1[1001];
int dp2[1001];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }    

    dp1[0] = 1e9;
    for(int i = 1; i <= n; i++)
    {
        int m = 0;
        for(int j = 0; j < i; j++)
        {
            if(dp1[j] > arr[i])
            {
                m = max(m, dp2[j]+1);
            }
        }
        dp1[i] = arr[i];
        dp2[i] = m;
    }

    int sol = 0;
    for(int i = 0; i <= n; i++)
    {
        sol = max(sol, dp2[i]);
    }

    cout << sol;
}