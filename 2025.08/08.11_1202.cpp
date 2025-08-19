#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, k;
vector<pair<int, int>> gems;
vector<int> bags;
priority_queue<int, vector<int>, less<int>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        gems.push_back({t1, t2});
    }
    for(int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        bags.push_back(t);
    }
    sort(bags.begin(), bags.end());
    sort(gems.begin(), gems.end());

    int idx = 0;
    long long sol = 0;
    for(int i = 0; i < bags.size(); i++)
    {
        // 가방보다 작은놈들 다 넣기
        while(idx < gems.size() && bags[i] >= gems[idx].first)
        {
            pq.push(gems[idx].second);
            idx++;
        }
        // 현재 상황에서 넣을 수 있는 제일 가치 높은 보석을 넣기
        if(!pq.empty())
        {
            sol += pq.top();
            pq.pop();
        }
    }

    cout << sol;
}