#include <stack>
#include <iostream>

int N, M;
int arr[9];
bool visited[9];

using namespace std;
void dfs(int num, int depth)
{
    if(depth == M)
    {
        for(int i = 0; i < M; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << "\n";
    }
    else
    {
        for(int i = N; i >= 1; i--)
        {
            if(!visited[i])
            {
                visited[i] = true;
                arr[depth] = i;
                dfs(i-1, depth+1);
                visited[i] = false;
            }
            
        }
    }
}

int main()
{
    cin >> N >> M;
    dfs(N,0);
}