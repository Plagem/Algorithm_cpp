#include <iostream>
#include <vector>
int INF = 10000000;

int main () 
{
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> distance(N, std::vector<int> (N, INF));
    for(int i=0; i<N; i++)
        distance[i][i] = 0;

    for(int i=0; i<M; i++) {
        int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        distance[tmp1-1][tmp2-1] = 1;
        distance[tmp2-1][tmp1-1] = 1;
    }

    std::vector<std::vector<int>> dp(N, std::vector<int> (N, INF));
    for(int i=0; i<N; i++) {
        std::vector<bool> visited(N, false);
        dp[i][i] = 0; visited[i] = true;


    }
}