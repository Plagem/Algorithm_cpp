#include <iostream>
using namespace std;

// N log N까지 가능. DP, 그리디, logN이면 이분탐색..
long long n, m;
long long sol;
long long arr[1000001];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long start = 1;
    long long end = 1000000000000;
    while(start <= end)
    {
        long long mid = (start + end) / 2;
        long long ballons = 0;
        for(int i = 0; i < n; i++)
        {
            ballons += mid / arr[i];
        }

        if(ballons >= m)
        {
            sol = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << sol;
}
