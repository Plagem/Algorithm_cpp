#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> road[101];
int dist[101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    
    // 배열 초기화
    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++)
        {
            if(i == j) continue;
            dist[i][j] = 1e9;
        }

    // 입력
    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(dist[a][b] > c)
        {
            dist[a][b] = c;
        }
    }

    // 플로이드 워셜 알고리즘
    for(int m = 1; m <= N; m++)
        for(int s = 1; s <= N; s++)
            for(int e = 1; e <= N; e++)
            {
                if(dist[s][e] > dist[s][m] + dist[m][e])
                    dist[s][e] = dist[s][m] + dist[m][e];
            }


    // 출력
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(dist[i][j] == 1e9) cout << "0 ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}