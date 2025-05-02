#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited(100001);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, N));

    while(!pq.empty())
    {
        int length = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        visited[cur] = true;

        if(cur == K)
        {
            cout << length;
            break;
        }

        if(0 <= cur-1 && visited[cur-1] == false)
            pq.push(make_pair(length+1, cur-1));
        if(cur+1 <= 100000 && visited[cur+1] == false)
            pq.push(make_pair(length+1, cur+1));
        if(cur*2 <= 100000 && visited[cur*2] == false)
            pq.push(make_pair(length, cur*2));
    }
}