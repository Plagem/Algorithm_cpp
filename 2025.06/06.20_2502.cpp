#include <iostream>
using namespace std;

int d, k;
int fibo[30];

int main()
{
    fibo[0] = 1; fibo[1] = 1;
    for(int i = 2; i < 29; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    cin >> d >> k;
    int sol1, sol2;
    sol2 = 0;
    for(int i = 0; i < 100000; i++)
    {
        // cur : 첫 날에 준 떡의 수
        int cur = i * fibo[d-3];
        // 
        int two = k - cur;
        if(two % fibo[d-2] == 0)
        {
            if(i < two / fibo[d-2])
            {
                cout << i << endl;
                cout << two / fibo[d-2];
                break;
            }
        }
    }
}   