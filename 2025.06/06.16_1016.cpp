#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

long long n, m;
int sol;
bool primer[1000001];

int main()
{
    cin >> n >> m;
    for(long long i = 2; i*i <= m; i++)
    {
        long long startpos = n - (n % (i*i)) + i*i;
        if(n % (i*i) == 0) startpos = n;

        for(; startpos <= m; startpos += i*i)
        {
            primer[startpos - n] = true;
        }
    }

    for(int i = 0; i <= 1000000; i++)
    {
        if(primer[i] == true)
        {
            sol++;
        }
    }

    cout << m - n - sol + 1;
}