#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> sol;
    int G;
    cin >> G;
    if(G % 2 == 1)
    {
        int i = 1;
        while(true)
        {
            if(G % i == 0 && G / i - ((i-1) / 2) * 2 >= 3)
            {
                sol.push_back(((G / i + ((i-1) / 2) * 2) + 1) / 2);
            }
            i += 2;

            if(i >= G) break;
        }
    }
    else
    {
        int i = 2;
        while(true)
        {
            if(G % i == 0 && (G / i - (i/2-1) * 2 - 1) % 2 != 0 && G / i - (i/2-1) * 2 - 1 >= 3)
            {
                sol.push_back((((G / i + (i/2-1) * 2 + 1)) + 1) / 2);
            }
            i += 2;

            if(i >= G) break;
        }
    }

    if(sol.size() < 1)
    {
        cout << "-1";
    }
    else
    {
        for(int i = sol.size() - 1; i >= 0; i--)
        {
            cout << sol[i] << "\n";
        }
    }
}