#include <iostream>
using namespace std;

unsigned int n, x;
bool arr[10000005];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr[t] = true;
    }

    int sol = 0;
    cin >> x;
    for(int i = 1; i <= (x-1)/2; i++)
    {
        if(arr[i] && arr[x-i])
        {
            sol++;
        }
    }

    cout << sol;
}