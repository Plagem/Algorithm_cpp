#include <iostream>
#include <algorithm>
using namespace std;

string s1, s2;
int lcs[1001][1001];

int main()
{
    cin >> s1 >> s2;
    for(int i = 1; i <= s1.size(); i++)
    {
        for(int j = 1; j <= s2.size(); j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                lcs[i][j] = lcs[i-1][j-1]+1; 
            }
            else
            {
                lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            }
        }
    }


    string sol;
    int curx = s1.size();
    int cury = s2.size();
    while(curx > 0 && cury > 0)
    {
        if(lcs[curx][cury] == lcs[curx-1][cury])
        {
            curx--;
        }
        else if(lcs[curx][cury] == lcs[curx][cury-1])
        {
            cury--;
        }
        else
        {
            sol += s1[curx-1];
            curx--; cury--;
        }
    }
    reverse(sol.begin(), sol.end());

    cout << lcs[s1.size()][s2.size()] << endl;
    if(sol.size() > 0)
    {
        cout << sol;
    }
}