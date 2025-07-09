#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

int n;
vector<string> v[200];
map<string, pair<int, int>> m;
bool visited[200][200];

int sum;

int main()
{
    cin >> n;
    for(int i = 0; i <= n+1; i++)
    { 
        string s;
        string st;
        getline(cin, s);
        istringstream str(s);

        while(str>>st)
        {
            v[i].push_back(st);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            m[v[i][j]] = {i, j};
        }
        sum += v[i].size();
    }

    if(v[n+1].size() != sum)
    {
        cout << "Impossible";
        return 0;
    }

    for(int i = 0; i < v[n+1].size(); i++)
    {
        string curs = v[n+1][i];
        pair<int, int> cp;

        if(m.find(v[n+1][i]) == m.end())
        {
           cout << "Impossible"; 
           return 0;
        }
        else
        {
            cp = m[v[n+1][i]];
        }

        if(visited[cp.first][cp.second])
        {
            cout << "Impossible";
            return 0;
        }

        // 단어 서순 체크
        if(cp.second > 0)
        {
            if(!visited[cp.first][cp.second-1])
            {
                cout << "Impossible";
                return 0;
            }
        }
        visited[cp.first][cp.second] = true;
    }

    cout << "Possible";
}