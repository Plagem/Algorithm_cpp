#include <iostream>
#include <algorithm>
using namespace std;

int N;
int syom[8];  // 입력받을 숫자
int sol[16];  // 결과를 저장할 배열
bool visited[16]; // 각 자리 사용 여부
bool used[8]; // 각 숫자의 사용 여부

void dfs(int depth)
{

    if (depth == N)
    {
        for (int i = 0; i < N * 2; i++)
        {
            cout << sol[i] << " ";
        }
        exit(0);
    }

    int firstEmpty = -1;
    for (int i = 0; i < N * 2; i++) {
        if (!visited[i]) {
            firstEmpty = i;
            break;
        }
    }
    
    if (firstEmpty == -1) return;

    for (int i = 0; i < N; i++)
    {
        if (used[i]) continue; 
        int nx = firstEmpty + syom[i] + 1;
        
        if (nx >= N * 2 || visited[nx]) continue;

        used[i] = true;
        visited[firstEmpty] = true;
        visited[nx] = true;
        sol[firstEmpty] = syom[i];
        sol[nx] = syom[i];

        dfs(depth + 1);

        used[i] = false;
        visited[firstEmpty] = false;
        visited[nx] = false;
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> syom[i];
    }

    sort(syom, syom + N);
    dfs(0);

    cout << "-1"; 
}
