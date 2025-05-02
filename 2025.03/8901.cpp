#include <iostream>
using namespace std;

int AB, BC, AC;

int main()
{
    int T;
    cin >> T;
    for(int _ = 0; _ < T; _++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        int AB, BC, AC;
        cin >> AB >> BC >> AC;

        int sol = 0;
        for(int i = 0; i <= min(A, B); i++)
        {
            int temp = AB * i;
            int remA = A - i; int remB = B - i;
            if(BC < AC)
            {
                temp += min(remA, C) * AC;
                int remC = C - min(remA, C);
                temp += min(remB, remC) * BC;
            }
            else
            {
                temp += min(remB, C) * BC;
                int remC = C - min(remB, C);
                temp += min(remA, remC) * AC;
            }

            sol = max(sol, temp);
        }

        cout << sol << "\n";
    }
}