#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[4][100001];
int dp[100001];
vector<int> savedp;

int biSearch(int a)
{
    int start = 0;
    int end = savedp.size();
    while(start < end)
    {
        int mid = (start + end) / 2;
        if(savedp[mid] < a)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return end;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    savedp.push_back(0);

    cin >> n;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        arr[2][arr[1][i]] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        arr[3][i] = arr[2][arr[0][i]];
    }
    
    // arr[3]에서 LIS 해주면 끝
    for(int i = 1; i <= n; i++)
    {
        int lb = biSearch(arr[3][i]);
        if(lb == savedp.size())
        {
            savedp.push_back(arr[3][i]);
        }
        else
        {
            savedp[lb] = min(savedp[lb], arr[3][i]);
        }
    }

    cout << savedp.size()-1;
}