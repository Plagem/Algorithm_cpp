#include <iostream>
using namespace std;

int cx, cy;
int n, m;
int arr[12][12];

int main()
{
    int t;
    cin >> n >> m >> t;
    cx = (t-1) / m;
    cy = t - (cx * m) - 1;

    cout << cx << ", " << cy;
}