#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;

int t;
int n, m;
ll sol;
vector<ll> A;
vector<ll> B;

map<ll, ll> Amap;
map<ll, ll> Bmap;

int main()
{
    cin >> t;
    cin >> n;

    A.push_back(0);
    B.push_back(0);

    for(int i = 1; i <= n; i++)
    {
        ll t;
        cin >> t;
        A.push_back(A[i-1] + t);
    }

    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        ll t;
        cin >> t;
        B.push_back(B[i-1] + t);
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            ll cur = A[j] - A[i];
            auto iter = Amap.find(cur);
            if(iter == Amap.end())
            {
                Amap.insert({cur, 1});
            }
            else
            {
                iter->second++;
            }
        }
    }

    for(int i = 0; i <= m; i++)
    {
        for(int j = i+1; j <= m; j++)
        {
            ll cur = B[j] - B[i];
            auto iter = Bmap.find(cur);
            if(iter == Bmap.end())
            {
                Bmap.insert({cur, 1});
            }
            else
            {
                iter->second++;
            }
        }
    }

    for(auto iter = Amap.begin(); iter != Amap.end(); iter++)
    {
        auto siter = Bmap.find(t-iter->first);
        if(siter != Bmap.end())
        {
            sol += iter->second * siter->second;
        }
    }

    cout << sol;
}