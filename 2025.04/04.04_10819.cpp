#include <iostream>
using namespace std;

int n;
int sol;
int arr[8];
int idfs[8];
int mdfs[8];
bool visited[8];

void dfs(int depth)
{
    if(depth == n)
    {
        // 최종 계산 로직
        int temp = 0;
        for(int i = 0; i < n-1; i++)
        {
            temp += abs(idfs[i] - idfs[i+1]);
        }
        if(sol < temp)
        {
            sol = max(sol, temp);
            for(int i = 0; i < n; i++)
            {
                mdfs[i] = idfs[i];
            }
        }
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == false)
        {
            idfs[depth] = arr[i];
            visited[i] = true;
            dfs(depth+1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dfs(0);

    cout << sol;
}