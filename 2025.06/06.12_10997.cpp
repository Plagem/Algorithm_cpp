#include <iostream>
using namespace std;

int arr[500][500];

int n;
int dir = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main()
{
    // 좌상단에서 시작, 전진 가능하면 전진
    // 전진 불가능(2칸 앞이 *이거나, 벽으로 막혀있을 때) 시 방향 전환
    // 둘 다 불가능하면 프로그램 종료
    cin >> n;
    if(n == 1)
    {
        cout << '*';
        return 0;
    }

    int sizex = 4*n - 1;
    int sizey = 4*n - 3;
    int curx = 0;
    int cury = 4*n - 4;

    while(true)
    {
        arr[curx][cury] = 1;
        
        bool blocked = false;
        bool padding = false;
        for(int i = 1; i <= 2; i++)
        {
            int nx = curx + dx[dir]*i;
            int ny = cury + dy[dir]*i;
            if(0 <= nx && nx < sizex && 0 <= ny && ny < sizey)
            {
                if(i == 2 && arr[nx][ny] == 1)
                {
                    padding = true;
                }
            }
            else
            {
                if(i == 1)
                    blocked = true;
            }
        }

        if(blocked && padding) break; 

        if(blocked && !padding) dir = (dir+1) % 4;
        else if(!blocked && padding) dir = (dir+1) % 4;

        if(arr[curx + dx[dir]*2][cury + dy[dir]*2] == 1) break;
        
        curx = curx + dx[dir];
        cury = cury + dy[dir];
    }

    for(int i = 0; i < sizex; i++)
    {
        if(i == 1)
        {
            cout << "*\n";
        }
        else
        {
            for(int j = 0; j < sizey; j++)
            {
                char a = arr[i][j] == 1 ? '*' : ' ';
                cout << a;
            }
            cout << "\n";
        }
    }
}