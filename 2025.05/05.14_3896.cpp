#include <iostream>
using namespace std;

#define INF 1299710;

int t, n;
bool primes[1299710];
int sol[1299710];

int lastprime = 2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int go = 0;
    for(int i = 2; i < 1299710; i++)
    {
        if(primes[i] == false)
        {
            for(int j = i; j < 1299710; j += i)
            {
                primes[j] = true;
            }
            for(int j = lastprime+1; j < i; j++)
            {
                sol[j] = go;
            }
            lastprime = i;
            go = 0;
        }
        go++;
    }

    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << sol[n] << '\n';
    }
}