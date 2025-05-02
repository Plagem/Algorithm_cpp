#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> road[501];
int dp[501][501];
int N, M, K;

int main()
{
    // initial
    for(int i = 0; i < 501; i++)
    {
        for(int j = 0; j < 501; j++)
        {
            dp[i][j] = 1e9;
        }
    }

    // input
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++)
    {
        int si, ei, ti, gi;
        cin >> si >> ei >> ti >> gi;
        vector<int> roadinfo = {ei, ti, gi};
        road[si].push_back(roadinfo);
    }

    // logic
    queue<vector<int>> q;
    vector<int> startinfo = {1, 0, 0};
    q.push(startinfo);
    while(!q.empty())
    {
        vector<int> curinfo = q.front();
        q.pop();
        int curpos = curinfo[0]; int jumpnum = curinfo[1]; int cost = curinfo[2];

        vector<int> eis;

        for(int i = 0; i < road[curpos].size(); i++)
        {
            int si, ei, ti, gi;
            si = curpos; ei = road[curpos][i][0]; ti = road[curpos][i][1]; gi = road[curpos][i][2];
            eis.push_back(ei);
            // 1. 점프 사용
            if(jumpnum < K)
            {
                dp[ei][jumpnum+1] = min(dp[ei][jumpnum+1], dp[si][jumpnum] + ti);
                //vector<int> nextinfo = {ei, jumpnum+1, dp[ei][jumpnum+1]};
            }
            // 2. 점프 미사용
            dp[ei][jumpnum] = min(dp[ei][jumpnum], dp[si][jumpnum] + 2 * ti - dp[si][jumpnum] % ti);
        }
    }
}