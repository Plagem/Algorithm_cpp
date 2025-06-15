// 콘센트 (그리디)
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int concent[10];
int arr[10000];

int main()
{
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < m; i++)
    {
        q.push(0);
    }
    
    sort(arr, arr+10000, [](int a, int b){ return a > b; });
    
    for(int i = 0; i < n; i++)
    {
        int cur = q.top(); q.pop();
        cur += arr[i];
        q.push(cur);
    }

    int sol = 0;
    while(!q.empty())
    {
        sol = max(sol, q.top()); 
        q.pop();
    }

    cout << q.top();
}