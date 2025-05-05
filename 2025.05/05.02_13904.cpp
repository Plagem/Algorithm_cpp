/*
Due-Date 4

1~4에서 4개 골라야 한다

1
1 20
-> 1 20 넣어두기

2
2 50
-> 2 50 넣어두기

3
3 30
4 10
-> Queue : 20, 50
-> 30 추가, 10 버리기

4
4 60
4 40
-> Queue : 20, 30, 50
20이 추가된 40보다 작다 -> 20 버리고 40, 60 추가

5
X

6
6 5
-> Queue : 30, 40, 50, 60
-> 5 추가

7
X

결과 : 30 + 40 + 50 + 60 + 5 = 185
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int maxDate;
vector<int> v[1001];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pq.push(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2; 
        maxDate = max(maxDate, t1);
        v[t1].push_back(t2);
    }

    for(int i = 1; i <= maxDate; i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            if(pq.size() < i)
            {
                pq.push(v[i][j]);
            }
            else
            {
                if(pq.top() < v[i][j])
                {
                    pq.pop();
                    pq.push(v[i][j]);
                }
            }
        }
    }

    int sol = 0;
    while(!pq.empty())
    {
        sol += pq.top(); pq.pop();
    }
    cout << sol;
}