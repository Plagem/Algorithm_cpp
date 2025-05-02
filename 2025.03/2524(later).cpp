#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double mp[4][2]; // 0, 1은 a의 meetpoint 2, 3은 b의 meetpoint

double dist(double ax, double ay, double bx, double by)
{
    return sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
}

int main()
{
    double ax, ay, bx, by;
    double p, q, r;

    cin >> ax >> ay >> bx >> by >> p >> q >> r;
     mp[0][0] = ax; 
     mp[0][1] = (p != 0) ? (r - q * ax) / p : ay;
     mp[1][0] = (q != 0) ? (r - p * ay) / q : ax;
     mp[1][1] = ay;
     
     mp[2][0] = bx; 
     mp[2][1] = (p != 0) ? (r - q * bx) / p : by;
     mp[3][0] = (q != 0) ? (r - p * by) / q : bx;
     mp[3][1] = by;

    double sol = abs(ax-bx) + abs(ay-by);
    sol = min(sol, dist(ax, ay, mp[0][0], mp[0][1]) + dist(bx, by, mp[2][0], mp[2][1]) + dist(mp[0][0], mp[0][1], mp[2][0], mp[2][1]));
    sol = min(sol, dist(ax, ay, mp[1][0], mp[1][1]) + dist(bx, by, mp[2][0], mp[2][1]) + dist(mp[1][0], mp[1][1], mp[2][0], mp[2][1]));
    sol = min(sol, dist(ax, ay, mp[0][0], mp[0][1]) + dist(bx, by, mp[3][0], mp[3][1]) + dist(mp[0][0], mp[0][1], mp[3][0], mp[3][1]));
    sol = min(sol, dist(ax, ay, mp[1][0], mp[1][1]) + dist(bx, by, mp[3][0], mp[3][1]) + dist(mp[1][0], mp[1][1], mp[3][0], mp[3][1]));

    cout << fixed << setprecision(12) << sol;
}