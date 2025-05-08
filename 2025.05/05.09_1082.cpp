#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;
int n, m;
int arr[10];

void Input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;
}

int findMin(int s, int e)
{
    int minidx = s;
    for(int i = s; i < e; i++)
    {
        if(arr[minidx] > arr[i]) minidx = i;
    }
    return minidx;
}

int main()
{
    int acc = 0;
    Input();
    if(m < arr[findMin(1, n)] || n == 1)
    {
        cout << 0;
        return 0;
    }

    acc += arr[findMin(1, n)];
    s += char(findMin(1, n))+'0';
    while(acc <= m)
    {
        if(acc+arr[findMin(0, n)] > m)
        {
            break;
        }
        acc += arr[findMin(0, n)];
        s += findMin(0, n)+'0';
    }

    for(int i = 0; i < s.size(); i++)
    {
        for(int j = n-1; j >= 0; j--)
        {
            int sidx = i == 0 ? 1 : 0;
            if(arr[j] - arr[findMin(sidx, n)] + acc <= m)
            {
                s[i] = j+'0';
                acc += arr[j] - arr[findMin(sidx, n)];
                break;
            }
        }
    }

    cout << s;
    return 0;
}