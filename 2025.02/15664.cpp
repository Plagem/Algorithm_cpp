#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

set<vector<int>> combinations;
int temp[8];
int nums[8];
int N, M;

void dfs(int idx, int depth)
{ 
    if(idx >= N) return;

    temp[depth-1] = nums[idx];

    if(depth == M)
    {
        // vector 만들고 set에 추가하기
        vector<int> tvector;
        for(int i = 0; i < M; i++)
        {
            tvector.push_back(temp[i]);
        }
        combinations.insert(tvector);
    }

    for(int i = idx+1; i < N; i++)
    {
        dfs(i, depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    sort(nums, nums+N);

    for(int i = 0; i < N; i++)
    {
        dfs(i, 1);
    }

    for(auto it = combinations.begin(); it != combinations.end(); it++)
    {
        vector<int> tvector = *it;
        for(int i = 0; i < M; i++)
        {
            cout << tvector[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}