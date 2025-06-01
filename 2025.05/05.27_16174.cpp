#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[64][64];
bool visited[64][64];
int x, y;


int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({0,0});
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();

        int curd = arr[cur.first][cur.second];
        
        if(curd == -1)
        {
            cout << "HaruHaru";
            return 0;
        }

        int nx, ny;
        nx = cur.first + curd;
        ny = cur.second;
        if(0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny])
        {
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
        nx = cur.first;
        ny = cur.second + curd;
        if(0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny])
        {
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    
    cout << "Hing";
}