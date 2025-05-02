// G4) 1806 부분합 : 
#include <iostream>
using namespace std;

bool founded = false;
int n, s, sol;
int arr[100001];
int parr[100001];

bool check(int interval)
{
    for(int i = 0; i <= n-interval; i++)
    {
        if(parr[i+interval] - parr[i] >= s)
        {
            founded = true;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        parr[i] = parr[i-1] + arr[i];
    }

    int start = 1; int end = n;
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(check(mid))
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }

    if(founded)
    {
        sol = start;
    }

    cout << sol;
}