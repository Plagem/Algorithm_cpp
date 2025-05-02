#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n, k;
vector<double> v;

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        double t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());

    double sol1, sol2;
    for(int i = k; i < n-k; i++)
    {
        sol1 += v[i];
    }
    sol2 = v[k]*k + v[n-1-k]*k + sol1;
    sol2 = round(sol2 * 100 / n) / 100;
    sol1 = round(sol1 * 100 / (n-2*k)) / 100;
    cout << fixed;  
    cout.precision(2);
    cout << sol1 << endl;
    cout << sol2;
}