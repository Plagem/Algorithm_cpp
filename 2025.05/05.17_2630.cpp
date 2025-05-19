#include <iostream>
using namespace std;

int n;
int white, blue;
int paper[128][128];

void rpaper(int x1, int y1, int x2, int y2)
{
    bool flag = true;
    for(int i = x1; i <= x2; i++)
    {
        for(int j = y1; j <= y2; j++)
        {
            //cout << paper[x1][y1] << paper[i][j] << endl;

            if(paper[x1][y1] != paper[i][j])
            {
                flag = false;
            }
        }
    }

    if(flag)
    {
        if(paper[x1][y1] == 0)
        {
            white++;
        }
        else
        {
            blue++;
        }
    }
    else
    {
        rpaper(x1, y1, (x1+x2)/2, (y1+y2)/2);
        rpaper((x1+x2)/2+1, (y1+y2)/2+1, x2, y2);
        rpaper((x1+x2)/2+1, y1, x2, (y1+y2)/2);
        rpaper(x1, (y1+y2)/2+1, (x1+x2)/2, y2);
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> paper[i][j];
        }
    }

    rpaper(0, 0, n-1, n-1);

    cout << white << endl;
    cout << blue << endl;
}