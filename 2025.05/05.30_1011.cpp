#include <iostream>
#include <cmath>
using namespace std;

int t;
int x, y;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        int dist = y - x;

        int sol = 0;
        int ol = ceil(sqrt(dist));
        
        sol = ol*2 - 1;
        if(ol*ol-ol >= dist)
        {
            sol--;
        }

        cout << sol << '\n';
    }
}