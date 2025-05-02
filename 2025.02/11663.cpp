#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dots;

int findIdx1(int num)
{
    int start = 0;
    int end = dots.size() - 1;
    int mid;

    while(start <= end)
    {
        mid = (start + end) / 2;
        if(dots[mid] < num)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return end;
}

int findIdx2(int num)
{
    int start = 0;
    int end = dots.size() - 1;
    int mid;

    while(start <= end)
    {
        mid = (start + end) / 2;
        if(dots[mid] > num)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return end;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        dots.push_back(temp);
    }
    sort(dots.begin(), dots.end());
   
    for(int i = 0; i < M; i++)
    {
        int start, end, startidx, endidx;
        startidx = 0; endidx = 0;
        cin >> start >> end;
        cout << findIdx2(end) - findIdx1(start)<< "\n";
    }
}