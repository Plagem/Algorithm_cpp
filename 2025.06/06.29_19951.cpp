#include <iostream>
using namespace std;

int n, m;
int arr[100001];
int sar[100002];
int kar[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;

        sar[t1] += t3; 
        sar[t2+1] -= t3;
    }

    for(int i = 1; i <= n; i++)
    {
        kar[i] = kar[i-1] + sar[i];

        cout << arr[i-1] + kar[i] << " ";
    }


}