// 2025.01.29
// Greedy

#include<iostream>
#include<algorithm>

long long arr[10001];

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    long long sol = 0;
    if(N%2 == 1) 
    {
        sol = max(arr[N-1], sol);
    }

    for(int i = 0; i < N/2; i++)
    {
        sol = max(arr[i] + arr[N-1-N%2-i], sol);
    }

    cout << sol;
}