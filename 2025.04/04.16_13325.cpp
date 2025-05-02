#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;

int n;
ll sol = 0;
vector<ll> tree;

int LRV(ll v, int h)
{
    if(h == n)
    {
        return tree[v];
    }
    else
    {
        ll left = LRV(v*2, h+1);
        ll right = LRV(v*2+1, h+1);
        sol += abs(left - right);
        return tree[v] + max(left, right);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    tree.push_back(0);
    tree.push_back(0);

    cin >> n;
    ll size = pow(2, n+1) - 2;
    for(ll i = 0; i < size; i++)
    {
        ll t;
        cin >> t;
        tree.push_back(t);
        sol += t;
    }

    LRV(1, 0);

    cout << sol;
}