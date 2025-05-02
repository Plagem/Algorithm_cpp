#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

// 현재 이모티콘 개수, 현재 시간, 현재 클립보드 내 이모티콘 개수
queue<tuple<int, int, int>> q;
int visited[2001][2001];
int n;

int main()
{
    cin >> n;
    if(n == 1) 
    {
        cout << 0; return 0;
    }
    q.push(make_tuple(1, 0, 0));
    visited[1][0] = true; 
    while(!q.empty())
    {
        tuple<int, int, int> cur = q.front(); q.pop();
        int curImot = get<0>(cur);
        int curTime = get<1>(cur);
        int curCopy = get<2>(cur);

        if(curImot == n)
        {
            cout << curTime;
            return 0;
        }

        if(!visited[curImot][curImot])
        {
            q.push(make_tuple(curImot, curTime+1, curImot));
            visited[curImot][curImot] = true;
        }

        if(curImot+curCopy <= 2000 && !visited[curImot+curCopy][curCopy])
        {
            q.push(make_tuple(curImot+curCopy, curTime+1, curCopy));
            visited[curImot+curCopy][curCopy] = true;
        }

        if(curImot-1 >= 1 && !visited[curImot-1])
        {
            q.push(make_tuple(curImot-1, curTime+1, curCopy));
            visited[curImot-1][curCopy] = true;
        }
    }
}