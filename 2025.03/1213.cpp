#include <string>
#include <iostream>
using namespace std;

int Alphabet[26];
string sol;

int main()
{
    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++)
    {
        Alphabet[s[i] - 65]++;
    }

    int holsuIdx = -1;

    for(int i = 0; i < 26; i++)
    {
        if(Alphabet[i] % 2 == 1)
        {
            if(holsuIdx != -1)
            {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            holsuIdx = i;
        }
        for(int j = 0; j < Alphabet[i] / 2; j++)
        {
            sol += i + 'A';
        }
    }
    if(holsuIdx != -1)
    {
        sol += holsuIdx + 'A';
    }
    for(int i = 25; i >= 0; i--)
    {
        for(int j = 0; j < Alphabet[i] / 2; j++)
        {
            sol += i + 'A';
        }
    }

    cout << sol;
}