#include <iostream>
#include <string>
using namespace std;

string s;

int sol = 0;

int main()
{
    cin >> s;

    int cur = 0;
    int i = 1;

    while(cur < s.length())
    {
        string snum = to_string(i);

        for(int j = 0; j < snum.length(); j++)
        {
            if(s[cur] == snum[j])
            {
                cur++;
            }
        }
        i++;
    }

    cout << i-1;
}