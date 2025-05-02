#include <iostream>
using namespace std;

long long n;
long double l, w, h;

bool checkPossible(long double d)
{
    long long ld = (long long)(l / d);
    long long wd = (long long)(w / d);
    long long hd = (long long)(h / d);

    if(ld * wd * hd >= n)
    {
        return true;
    }
    return false;
}

int main()
{
    cin >> n >> l >> w >> h;

    long double start = 0; 
    long double end = min(l, min(w, h));

    long double sol = 0;
    for(int i = 0; i < 200; i++)
    {
        long double mid = (start+end)/(double)2;

        if(checkPossible(mid))
        {
            start = mid;
            sol = mid;
        }
        else
        {
            end = mid;
        }
    }

    cout.precision(30);
    cout << fixed << sol;
}