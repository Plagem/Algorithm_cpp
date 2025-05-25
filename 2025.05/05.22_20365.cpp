#include <iostream>
#include <string>
using namespace std;

string s;
int n;
int sol = 1;


int main()
{
    cin >> n >> s;

    for(int i = 1; i < n; i++)
    {
        if(s[i-1] != s[i])
        {
            sol++;
        }
    }

    cout << 1 + sol/2;
}