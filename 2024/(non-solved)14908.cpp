/* 딱 봤을때 경우의 수 개많은데
dp는 아닌듯 하다. 중복되는 계산이 딱히 안보임.
그러니까 그리디 아닐까?

1000개중에 하나 넣고 보상금 총합 돌려본다
-> 제일 적은놈으로 투입

3	4	0
1	1000	0
2	2	0
5	5	0

-> 1번 투입 (3일)
3	4	0
1	1000	1000*3
2	2	2*3
5	5	5*3

-> 2번 투입
3	4	4
1	1000	0
2	2	2
5	5	5

->2-1
3	4	4
1	1000	0
2	2	2+

여기까지 생각하는데 대략 20분 걸린듯
 */
#include <iostream>

int tasks[1000][2];
int tempcost[1000];
bool visited[1000];
int sol[1000];

using namespace std;
int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> tasks[i][0] >> tasks[i][1];
        tempcost[i] = 0;
        visited[i] = false;
    }

    for(int i = 0; i < N; i++)
    {
        int minidx = 0;
        long long mincost = -1;
        for(int j = 0; j < N; j++)
        {
            if(visited[j]) continue;
            int taskday = tasks[j][0];
            long long temp = 0;
            for(int k = 0; k < N; k++)
            {
                if(visited[k]) continue;
                temp += tempcost[k];
            }
        }
        visited[minidx] = true;
    }
}