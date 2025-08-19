#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, k;
vector<int> spf(4000001);
vector<int> prime;

int main()
{
    cin >> n >> k;
    if(k > n/2)
    {
        k = n-k;
    }

    // SPF (Smallest Prime Factor)
    for(int i = 2; i <= n; i++)
    { 
        if(!spf[i])
        {
            prime.push_back(i);
            spf[i] = i;
        }

        for(int j = 0; (long long)i * prime[j] <= n; j++)
        {
            spf[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }

    // 소인수분해
    map<int, int> up;
    map<int, int> down;
    for(int i = n; i > n-k; i--)
    {
        int cur = i;
        while(cur != 1)
        {
            up[spf[cur]]++;
            cur /= spf[cur];
        }
    }
    for(int i = 1; i <= k; i++)
    {
        int cur = i;
        while(cur != 1)
        {
            down[spf[cur]]++;
            cur /= spf[cur];
        }
    }

    long long sol = 1;

    // 약분
    for(auto it = up.begin(); it != up.end(); it++)
    {
        if(down.find(it->first) != down.end())
        {   
            up[it->first] = it->second - down[it->first];
        }

        for(int i = 0; i < it->second ; i++)
        {
            sol *= (long long)it->first;
            sol %= 1000000007;
        }
    }

    cout << sol;
}