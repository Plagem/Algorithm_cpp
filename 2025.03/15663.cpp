#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

set<vector<int>> se;
int inputArr[8];
int arr[8];
bool used[8];
int N, M;

void dfs(int depth)
{
    if(depth == M)
    {
        vector<int> tv;
        for(int i = 0; i < M; i++)
        {
            tv.push_back(arr[i]);
        }
        se.insert(tv);
    }

    for(int i = 0; i < N; i++)
    {
        if(used[i] == true) continue;
        else
        {
            used[i] = true;
            arr[depth] = inputArr[i];
            dfs(depth+1);
            used[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> inputArr[i];
    }
    sort(inputArr, inputArr + N);

    dfs(0);

    for(auto it = se.begin(); it != se.end(); it++)
    {
        vector<int> tv = *it;
        for(int i = 0; i < tv.size(); i++)
        {
            cout << tv[i] << " ";
        }
        cout << "\n";
    }
}