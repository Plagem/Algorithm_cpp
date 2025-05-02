#include <iostream>

const int INF = 1e9;
int sol[1001];
int road[1001][1001];
bool visited[1001] = {false, };

using namespace std;
int main()
{
    // 주의점
    // 1. 중복간선을 처리할 것
    
    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++)
    {
        sol[i] = INF;
        for(int j = 1; j <= N; j++)
        {
            road[i][j] = INF;
        }
        road[i][i] = 0;
    }

    for(int i = 0; i < M; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        road[t1][t2] = min(road[t1][t2], t3);
    }
    int start, end;
    cin >> start >> end;
    
    visited[start] = true;
    for(int i = 1; i < N+1; i++)
        sol[i] = road[start][i];
    sol[start] = 0;


    for(int i = 0; i < N; i++)
    {
        int minidx = -1;
        for(int j = 1; j < N+1; j++)
        {
            if(visited[j]) continue;
            if(minidx == -1 || sol[j] < sol[minidx]) minidx = j;
        }
        visited[minidx] = true;

        if(minidx == -1 || sol[minidx] == INF) break;

        for(int j = 1; j < N+1; j++)
        {
            sol[j] = min(sol[j], sol[minidx] + road[minidx][j]);
        }
    }
}