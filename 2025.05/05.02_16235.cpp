#include <iostream>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>
#include <functional>
using namespace std;

float springTime, summerTime, fallTime, winterTime;

int loop;

int n, m, k;
int energy[11][11]; // 현재 땅의 양분이 저장되어있는 배열
int plusEnergy[11][11]; // 매 겨울마다 추가되는 양분
deque<int> tree[11][11]; // 나무의 정보(나이) 들어있는 벡터 배열
queue<pair<int, int>> nextTree; // 생성될 트리
queue<tuple<int, int, int>> deathTree; // r, c, age
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void Input()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            energy[i][j] = 5;
            cin >> plusEnergy[i][j];
        }
    }

    for(int i = 0; i < m; i++)
    {
        int x, y, age;
        cin >> x >> y >> age;
        tree[x][y].push_back(age);
    }
}

void Spring()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            deque<int> newTree;
            for(int l = 0; l < tree[i][j].size(); l++)
            {
                int curTree = tree[i][j][l];
                if(energy[i][j] >= curTree)
                {
                    if((curTree+1)%5 == 0)
                    {
                        nextTree.push(make_pair(i, j));
                    }
                    energy[i][j] -= curTree;
                    newTree.push_back(curTree+1);
                }
                else
                {
                    deathTree.push(make_tuple(i,j,curTree/2));
                }
            }
            tree[i][j] = newTree;
        }
    }
}

void Summer()
{
    while(!deathTree.empty())
    {
        auto cur = deathTree.front(); deathTree.pop();
        energy[get<0>(cur)][get<1>(cur)] += get<2>(cur);
    }
}

void Fall()
{
    while(!nextTree.empty())
    {
        auto cur = nextTree.front(); nextTree.pop();
        int nx, ny;
        for(int ii = 0; ii < 8; ii++)
        {
            nx = cur.first+dx[ii]; ny = cur.second+dy[ii];
            if(0 < nx && nx <= n && 0 < ny && ny <= n)
            {
                tree[nx][ny].push_front(1);
            }
        }
    }
}

void Winter()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            energy[i][j] += plusEnergy[i][j];
        }
    }
}

int main()
{
    Input();
    for(int i = 0; i < k; i++)
    {
        Spring(); 
        Summer();
        Fall(); 
        Winter();
    }

    int sol = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            sol += tree[i][j].size();
        }
    }

    cout << sol;
}