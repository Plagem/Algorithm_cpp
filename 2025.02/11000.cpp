#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> v;

    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v.push_back(make_pair(t1, t2));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++)
    {
        pq.push(v[i].second);
        if(pq.top() <= v[i].first) pq.pop();
    }

    cout << pq.size();
}