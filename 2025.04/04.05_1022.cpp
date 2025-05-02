// G3) 1022 소용돌이 예쁘게 출력하기 : 구현?
#include <iostream>
using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int maxI = 1;
int r1, c1, r2, c2;
int circle[50][50];

int getDigit(int a)
{
    if(a == 0) return 1;
    int digit = 0;
    while(a)
    {
        digit++;
        a /= 10;
    }
    return digit;
}

void make()
{
    int dirIdx = 0;
    int goSt = 1;
    int curGoSt = 0;
    int i, j, num;
    i = 0; j = 0; num = 1;
    //cout << "(" << i << ", " << j << ") : " << num << "\n";
    if(r1 <= i && i <= r2 && c1 <= j && j <= c2)
    {
        circle[i-r1][j-c1] = num;
    }

    for(int k = 0; k < 2e8; k++)
    {
        if(curGoSt >= goSt)
        {
            curGoSt = 0;
            dirIdx++;
            if(dirIdx % 2 == 0) goSt++;
        }
        if(dirIdx >= 4)
        {
            dirIdx = 0;
        }

        num++;
        curGoSt++;
        i += dx[dirIdx]; j += dy[dirIdx];

        if(r1 <= i && i <= r2 && c1 <= j && j <= c2)
        {
            circle[i-r1][j-c1] = num;
            maxI = max(maxI, num);
        }
        //cout << "(" << i << ", " << j << ") : " << num << "\n"; 
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> r1 >> c1 >> r2 >> c2;

    make();
    
    int maxDigit = getDigit(maxI);

    for(int i = 0; i <= r2-r1; i++)
    {
        for(int j = 0; j <= c2-c1; j++)
        {
            for(int k = 0; k < maxDigit - getDigit(circle[i][j]); k++)
            {
                cout << " ";
            }
            cout << circle[i][j] << " ";
        }
        cout << endl;
    }
}