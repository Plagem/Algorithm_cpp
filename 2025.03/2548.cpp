#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> prefixSum;

int solnum;
int minsum = 1e9;

int main()
{
    // Input
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++)
    {
        int lastPrefixSum = i == 0 ? 0 : prefixSum[i-1];
        prefixSum.push_back(lastPrefixSum + arr[i]);
    }

    // Logic
    for(int i = 0; i < n; i++)
    {
        int accsum = 0;
        accsum += (i+1)*arr[i] - prefixSum[i];
        accsum += (prefixSum[n-1] - prefixSum[i]) - (n-1-i)*arr[i];

        if(accsum == minsum && arr[i] < solnum) solnum = arr[i];
        if(accsum < minsum)
        {
            solnum = arr[i];
            minsum = accsum;
        }
    }

    cout << solnum;
}