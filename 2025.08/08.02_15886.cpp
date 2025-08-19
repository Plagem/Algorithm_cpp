#include <iostream>
#include <string>
using namespace std;

int n;
string s;

int main()
{
    int sol = 0;
    cin >> n >> s;
    if(s[0] == 'W') sol++;
    if(s[n-1] == 'E') sol++;
    for(int i = 1; i < n; i++)
    {
        if(s[i] == 'W' && s[i-1] == 'E')
            sol++;
    }
    cout << sol;
}