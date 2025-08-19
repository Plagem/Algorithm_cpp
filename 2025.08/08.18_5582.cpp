#include <iostream>
#include <string>
using namespace std;

string a, b;
int dp[4001][4001];

int main()
{
    cin >> a >> b;

    int sol = 0;
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < b.size(); j++)
        {
            if(a[i] != b[j])
            {
                dp[i+1][j+1] = 0;
            }
            else
            {
                dp[i+1][j+1] = dp[i][j] + 1;
                sol = max(sol, dp[i+1][j+1]);
            }
        }
    }

    cout << sol;
}