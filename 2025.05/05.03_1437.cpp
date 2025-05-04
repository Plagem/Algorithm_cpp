/*
log 2 = 0.301
log 3 = 0.477 (log2보다 1.5배 이상 높다)
log 4 = 0.602
log 5 = 0.698 (log2의 2.5배는 0.75니까 효율 안좋음)

-> 최대한 3 때려박고 이후 2?

6 - 33
7 - 322
8 - 332
9 - 333
10 - 3322 -> 10%3 = 1 -> 2 2개
11 - 3332 -> 11%3 = 2 -> 2 1개
12 - 3333 -> 12%3 = 0 -> 2 0개
 */

#include <iostream>
#include <vector>
using namespace std;

int n;
int sol = 1;
vector<int> bunhe;

int main()
{
    int num2, num3;
    cin >> n;
    if(n%3 == 1) num2 = 2;
    else if(n%3 == 2) num2 = 1;
    else num2 = 0;
    num3 = (n-2*num2)/3;

    if(n < 2)
    {
        cout << n;
    }
    else
    {
        for(int i = 0; i < num2; i++)
        {
            sol *= 2;
            sol %= 10007;
        }
        for(int i = 0; i < num3; i++)
        {
            sol *= 3;
            sol %= 10007;
        }

        cout << sol;
    }
}