#include <iostream>
using namespace std;

long long n, l;
long long arr[200001];
long long sum;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> l;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cn = 1;
    for(int i = n-1; i > 0; i--)
    {
        sum += arr[i];
        if(abs(arr[i-1]*cn-sum) >= l*cn)
        {
            cout << "unstable";
            exit(0);
        }
        cn++;
    }
    cout << "stable";
}