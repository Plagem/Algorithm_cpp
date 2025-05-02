// 2025.01.13
// dfs

#include <iostream>
#include <algorithm>

int N, M;
int arr[8];
int permutation[8];
bool visited[8];

using namespace std;

void dfs(int idx, int depth)
{
    if(depth == M)
    {
        for(int i = 0; i < M; i++)
        {
            cout << permutation[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for(int i = 0; i < N; i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                permutation[depth] = arr[i];
                dfs(0, depth+1);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    dfs(0, 0);
}