#include <iostream>
using namespace std;

int n, k;
int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        arr[i] = arr[i-1] + t;
    }

    int m = -1e9;
    for(int i = 0; i <= n-k; i++)
    {
        m = max(m, arr[i+k] - arr[i]);
    }

    cout << m;
}