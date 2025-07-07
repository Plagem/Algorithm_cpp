#include <iostream>
#include <vector>
using namespace std;

int n, k;
int arr[100000];



int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int start = 0;
    int end = 2000000;
    int sol = 0;
    while(start <= end) // start가 end일 때 마지막으로 갱신이 되어야 함
    {
        int mid = (start + end) / 2;

        int group = 0;
        int acc = 0;
        for(int i = 0; i < n; i++)
        {
            acc += arr[i];
            if(acc >= mid)
            {
                acc = 0; group++;
            }
        }

        if(group >= k) // == 부호가 포함되어있으니 여기서 sol을 갱신해줘야 함
        {
            sol = mid;
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }

    cout << sol;
}