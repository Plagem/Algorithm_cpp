#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int n, m;
map<string, string> v;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string gr; int k;
        cin >> gr >> k;
        for(int j = 0; j < k; j++)
        {
            string name;
            cin >> name;
            v[name] = gr;
        }
    }

    for(int i = 0; i < m; i++)
    {
        string name; int k;
        cin >> name >> k;
        if(k == 1)
        {
            if(v.find(name) != v.end())
            {
                cout << v.find(name)->second << '\n';
            }
        }
        else
        {
            for(auto iter = v.begin(); iter != v.end(); iter++)
            {
                if(iter->second == name)
                {
                    cout << iter->first << '\n';
                }
            }
        }
    }
}