#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s, t;

int main()
{
    cin >> s >> t;
    while(s.length() < t.length())
    {
        if(t[t.length()-1] == 'A')
        {
            t = t.substr(0, t.length()-1);
        }
        else
        {
            t = t.substr(0, t.length()-1);
            reverse(t.begin(), t.end());
        }
    }

    if(s == t)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}