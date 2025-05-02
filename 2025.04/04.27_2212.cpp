#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, k;
vector<ll> arr;
vector<ll> guri;

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        ll t;
        cin >> t;
        arr.push_back(t);
    }
    
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n-1; i++)
    {
        guri.push_back(arr[i+1] - arr[i]);
    }

    sort(guri.begin(), guri.end());

    ll sol = 0;
    for(int i = 0; i < max((ll)0, n-k); i++)
    {
        sol += guri[i];
    }

    cout << sol;
}