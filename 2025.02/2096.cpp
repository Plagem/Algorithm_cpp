#include <iostream>
using namespace std;

int N;
int t0, t1, t2;

int maxarr[3];
int minarr[3];
int tminarr[3];
int tmaxarr[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> t0 >> t1 >> t2;
        if(i == 0)
        {
            minarr[0] = t0; minarr[1] = t1; minarr[2] = t2;
            maxarr[0] = t0; maxarr[1] = t1; maxarr[2] = t2;
            continue;
        }
        tminarr[0] = min(minarr[0] + t0, minarr[1] + t0);
        tminarr[1] = min(min(minarr[0] + t1, minarr[1] + t1), minarr[2] + t1);
        tminarr[2] = min(minarr[1] + t2, minarr[2] + t2);

        tmaxarr[0] = max(maxarr[0] + t0, maxarr[1] + t0);
        tmaxarr[1] = max(max(maxarr[0] + t1, maxarr[1] + t1), maxarr[2] + t1);
        tmaxarr[2] = max(maxarr[1] + t2, maxarr[2] + t2);

        for(int i = 0; i < 3; i++)
        {
            minarr[i] = tminarr[i];
            maxarr[i] = tmaxarr[i];
        }
    }

    cout << max(maxarr[0], max(maxarr[1], maxarr[2])) << " " << min(minarr[0], min(minarr[1], minarr[2]));
}