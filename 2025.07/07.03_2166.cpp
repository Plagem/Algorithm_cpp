#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<double, double>> v;
double sol;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        double t1, t2;
        cin >> t1 >> t2;
        v.push_back({t1, t2});
    }

    for(int i = 0; i < n; i++)
    {
        sol += v[i].first * v[(i+1)%n].second - v[(i+1)%n].first * v[i].second;
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(sol) / 2;
}