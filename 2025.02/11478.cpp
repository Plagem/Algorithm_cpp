#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    set<string> ss;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        for(int j = i; j < s.length(); j++)
        {
            ss.insert(s.substr(i, j-i+1));
        }
    }

    cout << ss.size();
}