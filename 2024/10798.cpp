#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    vector<string> v;

    for(int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(i >= v[j].size()) continue;
            cout << v[j][i];
        }
    }
}